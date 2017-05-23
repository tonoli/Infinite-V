/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 20:34:51 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 01:14:36 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	color(int key, t_env *env)
{
	new_img(env);
	env->psy = (key == A || key == 1) ? env->psy * 25 : env->psy / 25;
	fractal_choice(env->fractal, env, &env->fract);
}

int		mouse_hook(int bouton, int x, int y, t_env *env)
{

//	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 110 && y <= 142)
		//reinit(env);
	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 160 && y <= 192)
		color(bouton, env);
	//if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 210 && y <= 242)
		//proj(env);
	//if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= 260 && y <= 292)
		//zoom(env, 1);
	//if (bouton == 2 && x >= CENTER && x <= CENTER + 32 && y >= 260 && y <= 292)
		//zoom(env, 2);
	if (bouton == 1 && x >= CENTER && x <= CENTER + 32 && y >= HEIGHT - 50 && y <= HEIGHT - 50 + 32)
		openhelp(env);
	if (bouton == 1 && x >= 1295 && x <= 1305 && y >= 605 && y <= 625)
		closehelp(env);
	return (0);
}

int		key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == A || key == D)
		color(key, env);
/*	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(env, key);
	else if (key == PLUS || key == MOINS)
		zoom(env, key);

	else if (key == SPACE)
		proj(env);
	else if (key == PAGEUP || key == PAGEDOWN)
		deepth(env, key);
	else if (key == R)
		reinit(env);
*/
	return (0);
}
