/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:57:54 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/25 15:30:54 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		fracol_map(char *argv)
{
	int			len;
	int			map;

	len = strlen(argv);
	map = fractal_number(argv);;
	if (len < 6 || map == 0)
		ft_error(0);
	return (map);
}

void	fractal_init(int map, t_env *env)
{
	if (map == 1)
		ft_julia(env, env->fract);
	else if (map == 2)
		ft_mandelbrot(env, env->fract);
/*	else if (map == 2)
		ft_burnship(env, env->fract);
	else if (map == 3)
		ft_buddhabrot(env, env->fract)
*/

}
int		main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
			ft_error(0);
	initenv(&env);
	env.fractal_nbr = fracol_map(argv[1]);
	fractal_init(env.fractal_nbr, &env);
	fill_img(&env);
	mlx_hook(env.win, 6, (1L << 6), mouse_move, &env);
	mlx_hook(env.win, 17, (1L << 17), &kill_program, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_loop(env.mlx);
}
