/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:21:11 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/24 01:40:10 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	*ft_fractol(void *arg)
{
	t_fract        *fract;
	t_env        *env;
	fract = (t_fract *)arg;
	env = fract->fol;
	fract->y = (fract->i * (HEIGHT / 5)) - 1;
	while (++fract->y < (HEIGHT / 5) * (fract->i + 1))
	{
		fract->x = -1;
		while (++fract->x < WIDTH)
			env->pfonct_fal[FINDEX](env, fract);
	}
	pthread_exit(0);
}
int		ft_thread(t_env *env)
{
	int         i;
	pthread_t   thread[5];
	t_fract        **fract;
	if (!(fract = (t_fract**)ft_memalloc(sizeof(t_fract*) * 5)))
		exit(0);
		i = -1;
	while (++i < 5)
	{
		if (!(fract[i] = (t_fract*)ft_memalloc(sizeof(t_fract))))
			exit(0);
		fract[i]->i = i;
		fract[i]->fol = env;
		pthread_create(&thread[i], NULL, &ft_fractol, fract[i]);
	}
	i = -1;
	while (++i < 5)
	{
		(void)pthread_join(thread[i], NULL);
		free(th[i]);
	}
	free(th);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	UI = (UI == 1) ? ft_ui(env) : 0;
	return (0);
}


int                 main(int ac, char **av)
{
    t_f     *env;
    if (ac != 2)
        ft_putendl("Usage : ./Fractol <fractol>");
    else
    {
        if (!(env = ft_create_struct(av[1])))
            exit(0);
        mlx_loop_hook(MLX, ft_thread, env);
        mlx_hook(WIN, KeyPress, KeyPressMask, ft_keypress, env);
        mlx_hook(WIN, MotionNotify, ButtonMotionMask, ft_move_mouse, env);
        mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_button, env);
        mlx_hook(WIN, DestroyNotify, Button1MotionMask, ft_exitprog, env);
        mlx_loop(MLX);
    }
    return (0);
}
