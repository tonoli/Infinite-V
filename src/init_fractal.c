/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:57:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/25 18:33:33 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fractol.h"

void	initenv(t_env *env)
{
	env->fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fract'onoli");
	env->ptr_img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = (int *)mlx_get_data_addr(env->ptr_img, &env->bpp,
		&env->size_line, &env->endian);
	env->iter_max = 500;
	env->zoom = 1;
	env->psy = 25;
	env->real = 0;
	env->ireal = 0;
	env->rot = 0;
	env->select = 1;
	env->move_v = 0;
	env->move_h = 0;
	env->red = 242;
	env->green = 15;
	env->blue = 32;
	new_menu(env);
}
