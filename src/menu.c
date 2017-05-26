/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 00:06:37 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 02:03:12 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

char 	*ft_name(t_env *env)
{
	if (env->fractal_nbr == 1)
		return ("Julia Fractal");
	if (env->fractal_nbr == 2)
		return ("Mandelbrot Fractal");
	if (env->fractal_nbr == 3)
		return ("Newton Fractal");
	if (env->fractal_nbr == 4)
		return ("Burnship Fractal");
	if (env->fractal_nbr == 5)
		return ("Sierpinski Fractal");
	if (env->fractal_nbr == 6)
		return ("Douady's Rabbit Fractal");
	if (env->fractal_nbr == 7)
		return ("Power Julia Fractal");
	if (env->fractal_nbr == 8)
		return ("Random Fractal");
	return (0) ;
}

void	files_menu(t_env *env)
{
	char *name;
	int c;
	int len;

	c = 70;
	name = ft_memalloc(sizeof(char) * 25);
	name = ft_name(env);
	len = ft_strlen(name);
	len *= 10;
	mlx_string_put(env->mlx, env->win, 89, 11, BLACK, "File");
	mlx_string_put(env->mlx, env->win, 90, 10, 0xBCBCBC, "File");
	mlx_string_put(env->mlx, env->win, 89 + c, 11, BLACK, "Edit");
	mlx_string_put(env->mlx, env->win, 90 + c, 10, 0xBCBCBC, "Edit");
	mlx_string_put(env->mlx, env->win, 89 + c * 2, 11, BLACK, "View");
	mlx_string_put(env->mlx, env->win, 90 + c * 2, 10, 0xBCBCBC, "View");
	mlx_string_put(env->mlx, env->win, 89 + c * 3, 11, BLACK, "Help");
	mlx_string_put(env->mlx, env->win, 90 + c * 3, 10, 0xBCBCBC, "Help");
	mlx_string_put(env->mlx, env->win, CENTRE - len / 2, 11, BLACK, name);
	mlx_string_put(env->mlx, env->win, CENTRE - len / 2, 10, 0xBCBCBC, name);
}

void	put_xmp(t_env *env)
{
	int width;
	int height;
	int c;

	c = 58;
	LOGO = mlx_xpm_file_to_image(env->mlx, "xpm/favicon.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, LOGO, CENTER, 5);
	SELECT = mlx_xpm_file_to_image(env->mlx, "xpm/selector.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, SELECT, CENTER, 60);
	RESET = mlx_xpm_file_to_image(env->mlx, "xpm/reset.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, RESET, CENTER, 60 + c);
	ICOLOR = mlx_xpm_file_to_image(env->mlx, "xpm/color.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ICOLOR, CENTER, 60 + c * 2);
	ISO = mlx_xpm_file_to_image(env->mlx, "xpm/iso.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ISO, CENTER, 60 + c * 3);
	ZOOM = mlx_xpm_file_to_image(env->mlx, "xpm/zoom.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ZOOM, CENTER, 60 + c * 4);
	HELP = mlx_xpm_file_to_image(env->mlx, "xpm/help.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, HELP, CENTER, HEIGHT - 50);
	files_menu(env);
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
			env->menu_data[x * WIDTH + y] = 0x3C3C3C;
			if ((x < 47 && x > 39) || ((x < 163 && x > 160) && y < 60)
			|| ((x < 105 && x > 102 && y < 60)) || ((x < 221 && x > 218 && y < 60))
			|| ((x < 279 && x > 276 && y < 60)) || ((x < 336 && x > 333) && y < 60))
				env->menu_data[x * WIDTH + y] = BLACK;
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
