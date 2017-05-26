/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:02:37 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 00:07:29 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


void	burnship_loop(t_fract *fract, t_env *env, t_poss poss)
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

void	ft_brunship(t_env *env, t_fract *fract)
{
	t_poss poss;

	poss.x = -1;
	while (++poss.x < HEIGHT)
	{
		poss.y = -1;
		while (++poss.y < WIDTH)
		{
			fract->cr = 0.285 - 0.5;
			fract->ci = 0.01 - 0.695;
			fract->zr = 1.5 * (poss.y + env->zoomy - WIDTH * 0.5) / (env->zoom * WIDTH * 0.5) + env->move_h;
			fract->zi = (poss.x + env->zoomx - HEIGHT * 0.5) / (env->zoom * HEIGHT * 0.5) + env->move_v;
			burnship_loop(fract, env, poss);
		}
	}
}

/*

void	burnship_loop(t_fract *fract, t_env *env, t_poss poss)
{
	double tmp;

	fract->iter = -1;
	while ((fract->zr * fract->zr + fract->zi * fract->zi) < 4
	&& ++fract->iter < env->iter_max)
	{
		tmp = fract->zi;
		fract->zi = fabs((double)(fract->zr * fract->zi + fract->zr * fract->zi + fract->ci));
		fract->zr = fabs((double)(fract->zr * fract->zr - tmp * tmp + fract->cr));
	}
	if (fract->iter != env->iter_max)
		ft_write_data(env, fract, poss.x, poss.y);
}

void	ft_brunship(t_env *env, t_fract *fract)
{
	t_poss poss;

	poss.y = -1;
	while (++poss.y < WIDTH)
	{
		poss.x = -1;
		while (++poss.x < HEIGHT)
		{
			fract->cr = (poss.y + env->zoomy - WIDTH) / ( env->zoom * WIDTH) + env->move_h;
			fract->ci = (poss.x + env->zoomx - HEIGHT) / (env->zoom * HEIGHT) + env->move_v;
			fract->zr = 0 + env->real;
			fract->zi = 0 + env->ireal;
			burnship_loop(fract, env, poss);
		}
	}
}

xtmp = fabsl(x) * fabsl(x) - fabsl(y) * fabsl(y) + r;
		ytmp = 2 * fabsl(x) * fabsl(y) + im;
		if (x == xtmp && y == ytmp)
			i = e->itermax - 1;
		x = xtmp;
		y = ytmp;

		int					mandelquad(t_env *e, long double r, long double im)
		{
			long double		x;
			long double		y;
			long double		xtmp;
			long double		ytmp;
			int				i;

			r = ((3.0 * r / W_W - 2.0) / e->zoom) + (e->shift[0] / W_W);
			im = ((-2.0 * im / W_H + 1.0) / e->zoom) + (e->shift[1] / W_H);
			x = 0;
			y = 0;
			i = -1;
			while (x * x + y * y <= DEFAULT_MAX_RADIUS && ++i < e->itermax)
			{
				xtmp = (x * x * x * x) - (6 * x * x * y * y) + (y * y * y * y) + r;
				ytmp = (4 * x * x * x * y) - (4 * x * y * y * y) + im;
				if (x == xtmp && y == ytmp)
					i = e->itermax - 1;
				x = xtmp;
				y = ytmp;
			}
			return (i);
		}
		*/
