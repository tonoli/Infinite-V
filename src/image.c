/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 00:02:44 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 00:54:58 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	new_img(t_env *env)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = (int*)mlx_get_data_addr(IMG, &BPP, &SL, &ENDIAN);
}

void	fill_img(t_env *env)
{
	draw_menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_menu, 0, 0);
	put_xmp(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_img, MENU_W, 0);
}
