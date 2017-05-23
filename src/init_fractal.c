/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:57:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 00:23:28 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fractol.h"

void	initenv(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fractal");
	env->ptr_img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = (int *)mlx_get_data_addr(env->ptr_img, &env->bpp,
		&env->size_line, &env->endian);
	env->iter_max = 100;
	env->zoom = 1;
	env->psy = 1;
	new_menu(env);
}
