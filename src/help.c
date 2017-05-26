/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 01:08:23 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/24 18:43:10 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	closehelp(t_env *env)
{
	new_img(env);
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}

void	openhelp(t_env *env)
{
	int x;
	int y;

	x = WIDTH - 360;
	while (++x < WIDTH - 50)
	{
		y = HEIGHT - 300;
		while (++y < HEIGHT - 50)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0xBCBCBC);
		}
	}
	mlx_string_put(env->mlx, env->win, WIDTH - 70, HEIGHT - 295, BLACK, "X");
	mlx_string_put(env->mlx, env->win, WIDTH - 340, HEIGHT - 280, 0xFF496C, "HELP MENU");
	mlx_string_put(env->mlx, env->win, WIDTH - 340, HEIGHT - 250, BLACK, "Rotation : A & D");
	mlx_string_put(env->mlx, env->win, WIDTH - 340, HEIGHT - 220, BLACK,
		"Deepth : PageUp & PageDown");
	mlx_string_put(env->mlx, env->win, WIDTH - 340, HEIGHT - 190, BLACK, "Zoom : + & -");
	mlx_string_put(env->mlx, env->win, WIDTH - 340, HEIGHT - 160, BLACK, "Move : Arrows");
	mlx_string_put(env->mlx, env->win, WIDTH - 340, HEIGHT - 130, BLACK, "Reset : R");
	mlx_string_put(env->mlx, env->win, WIDTH - 140, HEIGHT - 80, 0xFF496C, "(c)IT2M");
}
