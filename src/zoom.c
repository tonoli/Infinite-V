/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:24:36 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 19:27:35 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_zoom(int key, t_env *env)
{
	new_img(env);
	if (env->zoom < 1)
		env->zoom += (key == 1 || key == PLUS) ? 0.5 : 0;
	else
		env->zoom += (key == 1 || key == PLUS) ? 0.5 : -0.5;
	env->iter_max += 5;
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}

void	ft_zoomi(int bouton, t_env *env)
{
	new_img(env);
	if (bouton == 5)
	{
		env->iter_max += 2;
		env->zoom *= 1.1;
		env->zoomx += (env->mouse_x) * 1.05 / 10;
		env->zoomy += (env->mouse_y) * 1.05 / 10;
	}
	if (bouton == 4 && env->zoom > 0)
	{
		env->iter_max -= 2;
		env->zoom /= 1.1;
		env->zoomx -= (env->mouse_x / 10) / 1.1;
		env->zoomy -= (env->mouse_y / 10) / 1.1;
	}
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}
