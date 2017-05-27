/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:48:12 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 19:22:56 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	power_loop(t_fract *fract, t_env *env, t_poss poss)
{
	double tmp;

	fract->iter = -1;
	while ((fract->zr * fract->zr + fract->zi * fract->zi) < 4
	&& ++fract->iter < env->iter_max)
	{
		tmp = fract->zr;
		fract->zr = fract->zr * fract->zr * fract->zr - 3 * fract->zi *
		fract->zi * fract->zr + fract->cr;
		fract->zi = 3 * fract->zi * tmp * tmp - fract->zi * fract->zi *
		fract->zi + fract->ci;
	}
	if (fract->iter != env->iter_max)
		ft_write_data(env, fract, poss.x, poss.y);
	if (fract->iter == env->iter_max)
		DATA[poss.x * WIDTH + poss.y] = 0x151515;
}

void		ft_julpower(t_env *env, t_fract *fract)
{
	t_poss poss;

	poss.x = -1;
	while (++poss.x < HEIGHT)
	{
		poss.y = -1;
		while (++poss.y < WIDTH)
		{
			fract->cr = -0.561923 + env->real;
			fract->ci = 0.13 + env->ireal;
			fract->zr = 1.5 * (poss.y + env->zoomy - WIDTH * 0.5) /
			(env->zoom * WIDTH * 0.5) + env->move_h;
			fract->zi = (poss.x + env->zoomx - HEIGHT * 0.5) /
			(env->zoom * HEIGHT * 0.5) + env->move_v;
			power_loop(fract, env, poss);
		}
	}
}
