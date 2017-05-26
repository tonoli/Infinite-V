/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 00:02:44 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/25 17:00:49 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	new_img(t_env *env)
{
	if (IMG)
		mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = (int*)mlx_get_data_addr(IMG, &BPP, &SL, &ENDIAN);
}

void	fill_img(t_env *env)
{
	draw_menu(env);
	//printf("Red : %d \n Green : %d \n Blue : %d \n", RO, GR, BL);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_menu, 0, 0);
	put_xmp(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_img, MENU_W, 47);
}

int		ft_color(int a, int r, int g, int b)
{
	return (((a & 0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) << 8) +
		(b & 0xff));
}

void	ft_write_data(t_env *env, t_fract *fract, int x, int y)
{
	int     color;
	if (x < 0 || x >= HEIGHT || y  < 0 || y >= WIDTH)
		return ;
	color = ft_color(0, (RO * fract->iter) / env->iter_max,
	(GR * fract->iter) / env->iter_max, (BL * fract->iter) / env->iter_max);
	if (fract->iter == -1)
		color = 0;
	*(int*)&DATA[(x * WIDTH + y)] = color + env->psy;
}
