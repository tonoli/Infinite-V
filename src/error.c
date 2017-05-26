/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:59:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 01:57:36 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		kill_program(void)
{
	exit(0);
	return(0);
}

void	ft_error(int i)
{
	if (i == 0)
	{
		ft_puterror("Usage : ./fractol <fractal name> \n -julia \n -mandelbrot \
		\n -buddhabrot \n -burnship \n -dragon \n -fibonacci \n -douady \
		\n -newton");
	}
}

int		fractal_number(char *argv)
{
	if (ft_strncmp("-julia", argv, 7) == 0)
		return (1);
	else if (ft_strncmp("-mandelbrot", argv, 12) == 0)
		return (2);
	else if (ft_strncmp("-newton", argv, 8) == 0)
		return (3);
	else if (ft_strncmp("-burnship", argv, 10) == 0)
		return (4);
	else if (ft_strncmp("-sierpinski", argv, 12) == 0)
		return (5);
	else if (ft_strncmp("-rabbit", argv, 11) == 0)
		return (6);
	else if (ft_strncmp("-power", argv, 8) == 0)
		return (7);
	else if (ft_strncmp("-random", argv, 8) == 0)
		return (4);
	return (0);
}
