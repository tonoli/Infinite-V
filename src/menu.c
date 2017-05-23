/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 00:06:37 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 01:03:06 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_xmp(t_env *env)
{
	int width;
	int height;

	LOGO = mlx_xpm_file_to_image(env->mlx, "xpm/favicon.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, LOGO, CENTER, 5);
	RESET = mlx_xpm_file_to_image(env->mlx, "xpm/reset.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, RESET, CENTER, 110);
	ICOLOR = mlx_xpm_file_to_image(env->mlx, "xpm/color.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ICOLOR, CENTER, 160);
	ISO = mlx_xpm_file_to_image(env->mlx, "xpm/iso.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ISO, CENTER, 210);
	ZOOM = mlx_xpm_file_to_image(env->mlx, "xpm/zoom.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ZOOM, CENTER, 260);
	HELP = mlx_xpm_file_to_image(env->mlx, "xpm/help.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, HELP, CENTER, HEIGHT - 50);
}

void	draw_menu(t_env *env)
{
	int x;
	int y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			env->menu_data[x * WIDTH + y] = WHITE;
			if ((x < 42 && x > 39) || (x < 150 && x > 147)
			|| (x < 105 && x > 102) || (x < 200 && x > 197)
			|| (x < 250 && x > 247) || (x < 300 && x > 297))
				env->menu_data[x * WIDTH + y] = 0x000000;
		}
	}
}

void	new_menu(t_env *env)
{
	int	bpp;
	int	size_line;
	int	endian;

	env->ptr_menu = mlx_new_image(MLX, WIDTH, HEIGHT);
	env->menu_data = (int*)mlx_get_data_addr(env->ptr_menu, &bpp,
		&size_line, &endian);
}
