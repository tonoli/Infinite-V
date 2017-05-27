/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:21:56 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 16:46:22 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_select(t_env *env)
{
	env->select = (env->select == 1) ? 0 : 1;
}

void	ft_reset(t_env *env)
{
	new_img(env);
	env->real = 0;
	env->ireal = 0;
	env->red = 242;
	env->green = 15;
	env->blue = 32;
	env->move_v = 0;
	env->move_h = 0;
	env->zoom = 1;
	env->psy = 25;
	env->rot = 0;
	env->zoomx = 0;
	env->zoomy = 0;
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}

void	ft_switch(t_env *env)
{
	ft_reset(env);
	if (env->fractal_nbr == 8)
		env->fractal_nbr = 1;
	else
		env->fractal_nbr++;
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}

void	ft_setcolor(int key, t_env *env)
{
	new_img(env);
	if (env->psy == 25)
		env->psy = (key == A || key == 1) ? env->psy * 25 : 25;
	else
		env->psy = (key == A || key == 1) ? env->psy * 25 : env->psy / 25;
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}

void	ft_random_color(t_env *env)
{
	new_img(env);
	env->red = rand() % 256;
	env->green = rand() % 256;
	env->blue = rand() % 256;
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}
