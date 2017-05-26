/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:28:13 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/24 23:43:19 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
/*
			fract->cr = -0.9;
			fract->ci = 0.27010;

*/
void	julia_init(t_fract *fract)
{
	fract->x1 = -1;
	fract->x2 = 1;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
}

void	julia_loop(t_fract *fract, t_env *env, t_poss poss)
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
}

void	ft_julia(t_env *env, t_fract *fract)
{
	t_poss poss;

	julia_init(fract);
	poss.x = -1;
	env->iter_max = 50;
	while (++poss.x < HEIGHT)
	{
		poss.y = -1;
		while (++poss.y < WIDTH)
		{
			fract->cr = 0.285 + env->real;
			fract->ci = 0.01 + env->ireal;
			fract->zr = 1.5 * (poss.y - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->move_h;
			fract->zi = (poss.x - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->move_v;
			julia_loop(fract, env, poss);
		}
	}
}
