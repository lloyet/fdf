/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 08:55:56 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:36:53 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_env		*free_env(t_env *mlx)
{
	if (mlx)
	{
		if (mlx->win)
			ft_memdel((void **)&mlx->win);
		if (mlx->img)
			free_img(mlx->mlx, mlx->img);
		if (mlx->mouse)
			ft_memdel((void **)&mlx->mouse);
		if (mlx->cam)
			free_cam(mlx->cam);
		ft_memdel((void **)&mlx);
	}
	return (0);
}

t_win		*new_window(void)
{
	t_win	*win;

	if (!(win = (struct s_win *)ft_memalloc(sizeof(struct s_win) + 1)))
		return (0);
	win->width = WIDTH;
	win->height = HEIGHT;
	return (win);
}

t_env		*new_env(void)
{
	t_env	*mlx;

	if (!(mlx = (struct s_env *)ft_memalloc(sizeof(struct s_env) + 1)))
		return (0);
	if (!(mlx->mlx = mlx_init()))
		return (free_env(mlx));
	if (!(mlx->win = new_window()))
		return (free_env(mlx));
	if (!(mlx->img = new_img(mlx->mlx)))
		return (free_env(mlx));
	if (!(mlx->mouse = (struct s_mouse *)ft_memalloc(sizeof(struct s_mouse) + 1)))
		return (free_env(mlx));
	mlx->cam = 0;
	return (mlx);
}
