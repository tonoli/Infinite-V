/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:53:21 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 15:21:34 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_sierpinski(t_env *env, t_fract *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			if (!((x / 1) % 3 == 1 && (y / 1) % 3 == 1)
					&&
					!((x / 3) % 3 == 1 && (y / 3) % 3 == 1)
					&&
					!((x / 9) % 3 == 1 && (y / 9) % 3 == 1)
					&&
					!((x / 27) % 3 == 1 && (y / 27) % 3 == 1)
					&&
					!((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
				ft_write_data(env, fract, x + env->move_h, y + env->move_v);
			else
				DATA[x * WIDTH + y] = 0x151515;
			x++;
		}
		y++;
	}
}
