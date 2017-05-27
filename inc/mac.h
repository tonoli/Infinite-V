/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 20:47:46 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/26 14:59:05 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_H
# define MAC_H

# define MLX env->mlx
# define WIN env->win
# define IMG env->ptr_img
# define DATA env->img_data
# define BPP env->bpp
# define SL env->size_line
# define ENDIAN env->endian

# define LOGO env->icon_logo
# define SELECT env->icon_select
# define HELP env->icon_help
# define HELPI env->help
# define RESET env->icon_reset
# define ICOLOR env->icon_color
# define ISO env->icon_fract
# define ZOOM env->icon_zoom

# define WIDTH		1560
# define HEIGHT		1200
# define CENTRE		WIDTH/2
# define MENU_W		60

# define CENTER		(MENU_W / 2) - 16

# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define PLUS		69
# define MOINS		78
# define PAGEUP		116
# define PAGEDOWN	121
# define SPACE		49
# define ESC_KEY	53
# define W			13
# define S			1
# define A			0
# define D			2
# define Z			6
# define X			7
# define C			8
# define V			9
# define R			15

# define LIGHTBLUE	0x4FC3F7
# define WHITE		0xFFFFFF
# define RED		0xF44336
# define GREEN		0x4CAF50
# define ORANGE		0xFB8C00
# define GREY		0x757575
# define BROWN		0x795548
# define BLACK		0x000000

# define RO	env->red
# define GR	env->green
# define BL	env->blue

#endif
