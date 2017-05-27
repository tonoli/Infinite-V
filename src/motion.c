/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 20:34:51 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 15:35:41 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_move(int key, t_env *env)
{
	new_img(env);
	if (key == UP)
		env->move_v += 0.02 / env->zoom;
	else if (key == DOWN)
		env->move_v -= 0.02 / env->zoom;
	else if (key == LEFT)
		env->move_h += 0.02 / env->zoom;
	else if (key == RIGHT)
		env->move_h -= 0.02 / env->zoom;
	fractal_init(env->fractal_nbr, env);
	fill_img(env);
}

static void	menu_butons(int bouton, int x, int y, t_env *env)
{
	if (((bouton == 1) || (bouton == 2)) && x >= CENTER && x <= CENTER + 32 &&
		y >= 292 && y <= 324)
		ft_zoom(bouton, env);
	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= HEIGHT - 50 &&
		y <= HEIGHT - 50 + 32)
		openhelp(env);
	if (bouton == 1 && x >= WIDTH - 70 && x <= WIDTH - 60 &&
		y >= HEIGHT - 295 && y <= HEIGHT - 275)
		closehelp(env);
}

int			mouse_hook(int bouton, int x, int y, t_env *env)
{
	if (env->select == 1 && ((bouton == 5) || (bouton == 4)) && x > 60 &&
		x < WIDTH && y > 47 && y < HEIGHT)
		ft_zoomi(bouton, env);
	if (env->select == 0 && (bouton == 1) && x > 60 && x < WIDTH &&
		y > 47 && y < HEIGHT)
		ft_select(env);
	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 60 && y <= 92)
		ft_select(env);
	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 118 && y <= 150)
		ft_reset(env);
	if (((bouton == 1) || (bouton == 2)) && x >= CENTER && x <= CENTER + 32 &&
		y >= 176 && y <= 206)
		ft_setcolor(bouton, env);
	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 234 && y <= 266)
		ft_random_color(env);
	menu_butons(bouton, x, y, env);
	return (0);
}

int			key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == A || key == D)
		ft_setcolor(key, env);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_move(key, env);
	else if (key == S)
		ft_select(env);
	else if (key == SPACE)
		ft_switch(env);
	else if (key == PLUS || key == MOINS)
		ft_zoom(key, env);
	else if (key == R)
		ft_reset(env);
	return (0);
}

int			mouse_move(int x, int y, t_env *env)
{
	env->mouse_x = x;
	env->mouse_y = y;
	if (env->select == 0)
	{
		new_img(env);
		if (x < 60 || x > WIDTH || y < 47 || y > HEIGHT)
			return (0);
		env->real = (((float)x - 800) / WIDTH) * 2;
		env->ireal = (((float)y - 800) / HEIGHT) * 2;
		fractal_init(env->fractal_nbr, env);
		fill_img(env);
	}
	return (0);
}
