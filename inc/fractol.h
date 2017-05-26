/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:09:04 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/25 18:17:15 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "mac.h"
# include <math.h>
# include <stdio.h>

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
	int 	image_w;
	int 	image_h;

	void	*icon_logo;
	void	*icon_select;
	void	*icon_help;
	int		help;
	void	*icon_color;
	void	*icon_reset;
	void	*icon_fract;
	void	*icon_zoom;
	int		img_hight;
	int		img_width;


	int		fractal_nbr;
	int		select;
	int		select_menu;
	double	move_v;
	double	move_h;
	double	zoom;
	double	z;
	double	rot;
	double	real;
	double	ireal;
	int		red;
	int		green;
	int		blue;
	int		psy;
	int		iter_max;

	int		mouse_x;
	int		mouse_y;

	int		bpp;
	int		size_line;
	int		endian;
	t_fract	*fract;
}					t_env;

void	fractal_init(int map, t_env *env);
void	ft_mandelbrot(t_env *env, t_fract *fract);
void	ft_julia(t_env *env, t_fract *fract);
void	ft_buddhabrot(t_env *env, t_fract *fract);
void	initenv(t_env *env);
void	draw_menu(t_env *env);
void	new_menu(t_env *env);
void	new_img(t_env *env);
int		key_hook(int key, t_env *env);
int		mouse_hook(int bouton, int x, int y, t_env *env);
int		mouse_move(int x, int y, t_env *env);
void	fill_img(t_env *env);
void	put_xmp(t_env *env);
void	closehelp(t_env *env);
void	openhelp(t_env *env);
int		kill_program(void);
int 	fractal_number(char *argv);
void	ft_error(int i);
void	ft_write_data(t_env *env, t_fract *fract, int x, int y);
char	*ft_name(t_env *env);

#endif
