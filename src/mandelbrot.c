/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:26:45 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 19:25:04 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		mandelbrot_loop(t_fract *fract, t_env *env, t_poss poss)
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
		ft_write_data(env, fract, poss.x, poss.y);
	else
		DATA[poss.x * WIDTH + poss.y] = 0x151515;
}

void			ft_mandelbrot(t_env *env, t_fract *fract)
{
	t_poss poss;

	poss.y = -1;
	while (++poss.y < WIDTH)
	{
		poss.x = -1;
		while (++poss.x < HEIGHT)
		{
			fract->cr = 1.5 * (poss.y + env->zoomy - WIDTH / 2) /
				(0.5 * env->zoom * WIDTH) + env->move_h - 0.6;
			fract->ci = (poss.x + env->zoomx - HEIGHT / 2) /
				(0.5 * env->zoom * HEIGHT) + env->move_v;
			fract->zr = 0 + env->real;
			fract->zi = 0 + env->ireal;
			mandelbrot_loop(fract, env, poss);
		}
	}
}
