/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:57:54 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 01:12:36 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		fracol_map(char *argv)
{
	int			len;

	len = strlen(argv);
	if (len < 6 || ( ft_strncmp("-julia", argv, 7) != 0
	&& ft_strncmp("-mandelbrot", argv, 12) != 0
	&& ft_strncmp("-fractal", argv, 9) != 0))
		ft_puterror("ERROR : input is not compatible \n Usage : ./fractol <fractal name> \n [-julia | -mandelbrot | -fractal]");
	else
	{
		if (ft_strncmp("-julia", argv, 7) == 0)
			return (0);
		if (ft_strncmp("-mandelbrot", argv, 12) == 0)
			return (1);
		if (ft_strncmp("-fractal", argv, 9) == 0)
			return (2);
	}
	return (3);
}

void	fractal_choice(int map, t_env *env, t_fract *fract)
{
	if (map == 0)
		ft_julia(env, fract);
	else if (map == 1)
		ft_mandelbrot(env, fract);
/*	else if (map == 3)
		ft_buddhabrot(env, fract);*/

}
int		main(int argc, char **argv)
{
	t_env		env;
	t_fract		fract;

	if (argc != 2)
			ft_puterror("Usage : ./fractol <fractal name> \n [-julia | -mandelbrot | -fractal]");

	initenv(&env);
	env.fractal = fracol_map(argv[1]);
	fractal_choice(env.fractal, &env, &fract);
	fill_img(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_loop(env.mlx);
}
