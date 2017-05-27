/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:25:07 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 19:23:01 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	newton_loop(t_fract *fract, t_env *env, t_poss poss)
{
	double tmp;

	fract->iter = -1;
	while ((fract->zr * fract->zr + fract->zi * fract->zi) < 4
	&& ++fract->iter < env->iter_max)
	{
		tmp = fract->zr;
		fract->zr = fract->zr * fract->zr - fract->zi * fract->zi + fract->cr;
		fract->zi = 2 * fract->zi * tmp + fract->ci;
	}
	if (fract->iter != env->iter_max)
		ft_write_data(env, env->fract, poss.x, poss.y);
	if (fract->iter == env->iter_max)
		DATA[poss.x * WIDTH + poss.y] = 0x151515;
}

void		ft_newton(t_env *env, t_fract *fract)
{
	t_poss poss;

	poss.x = -1;
	while (++poss.x < HEIGHT)
	{
		poss.y = -1;
		while (++poss.y < WIDTH)
		{
			fract->cr = -0.9;
			fract->ci = 0.27010;
			fract->zr = 1.5 * (poss.y + env->zoomy - WIDTH * 0.5) /
				(env->zoom * WIDTH * 0.5) + env->move_h;
			fract->zi = (poss.x + env->zoomx - HEIGHT * 0.5) /
				(env->zoom * HEIGHT * 0.5) + env->move_v;
			newton_loop(fract, env, poss);
		}
	}
}
