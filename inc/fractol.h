/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:09:04 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/23 01:12:55 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "mac.h"
# include <math.h>

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}					t_point;

typedef struct		s_poss
{
	int		x;
	int		y;
}					t_poss;

typedef struct		s_diff
{
	int		x;
	int		y;
	int		absx;
	int		absy;
}					t_diff;

typedef struct			s_fract
{
	int					i;
	long double			x1;
	long double			x2;
	long double			y1;
	long double			y2;
	long double 		zoomr;
	long double 		zoomi;
	int					x;
	int					y;
	long double			zi;
	long double			zr;
	long double			ci;
	long double			cr;
	long				iter;
	void*				next;
}						t_fract;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	int		*img_data;
	void	*ptr_menu;
	int		*menu_data;
	void	*icon_logo;
	void	*icon_help;
	int		help;
	void	*icon_color;
	void	*icon_reset;
	void	*icon_fract;
	void	*icon_zoom;
	int		img_hight;
	int		img_width;
	int		fractal;
	double	move_v;
	double	move_h;
	double	zoom;
	int		psy;
	int		bpp;
	int		size_line;
	int		endian;
	int		iter_max;
	t_fract	fract;
}					t_env;

void	fractal_choice(int map, t_env *env, t_fract *fract);
void	ft_mandelbrot(t_env *env, t_fract *fract);
void	ft_julia(t_env *env, t_fract *fract);
void	ft_buddhabrot(t_env *env, t_fract *fract);
void	initenv(t_env *env);
void	draw_menu(t_env *env);
void	new_menu(t_env *env);
void	new_img(t_env *env);
int		key_hook(int key, t_env *env);
int		mouse_hook(int bouton, int x, int y, t_env *env);
void	fill_img(t_env *env);
void	put_xmp(t_env *env);
void	closehelp(t_env *env);
void	openhelp(t_env *env);

#endif
