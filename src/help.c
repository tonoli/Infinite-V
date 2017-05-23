/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 01:08:23 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 01:12:03 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	closehelp(t_env *env)
{
	new_img(env);
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
			mlx_pixel_put(env->mlx, env->win, x, y, WHITE);
		}
	}
	mlx_string_put(env->mlx, env->win, 1295, 605, BLACK, "X");
	mlx_string_put(env->mlx, env->win, 1020, 620, GREEN, "HELP MENU");
	mlx_string_put(env->mlx, env->win, 1020, 650, RED, "Rotation : A & D");
	mlx_string_put(env->mlx, env->win, 1020, 680, RED,
		"Deepth : PageUp & PageDown");
	mlx_string_put(env->mlx, env->win, 1020, 710, RED, "Zoom : + & -");
	mlx_string_put(env->mlx, env->win, 1020, 740, RED, "Move : Arrows");
	mlx_string_put(env->mlx, env->win, 1020, 770, RED, "Reset : R");
	mlx_string_put(env->mlx, env->win, 1230, 820, BLACK, "(c)IT2M");
}
