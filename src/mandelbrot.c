/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:26:45 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 00:45:55 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_init(t_fract *fract)
{
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
}

void	mandelbrot_loop(t_fract *fract, t_env *env, t_poss poss)
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
		DATA[poss.x * WIDTH + poss.y] = 255 * fract->iter / env->iter_max;
}

void	ft_mandelbrot(t_env *env, t_fract *fract)
{
	t_poss poss;

	mandelbrot_init(fract);
	fract->zoomr = WIDTH / (fract->x2 - fract->x1);
	fract->zoomi = HEIGHT / (fract->y2 - fract->y1);
	poss.x = -1;
	env->iter_max = 50;
	while (++poss.x < HEIGHT)
	{
		poss.y = -1;
		while (++poss.y < WIDTH)
		{
			fract->cr = poss.y / fract->zoomr + fract->x1;
			fract->ci = poss.x / fract->zoomi + fract->y1;
			fract->zr = 0;
			fract->zi = 0;
			mandelbrot_loop(fract, env, poss);
		}
	}
}
