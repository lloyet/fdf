/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 11:52:04 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 13:03:16 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_cam		*new_cam(void)
{
	t_cam	*cam;

	if (!(cam = (struct s_cam *)ft_memalloc(sizeof(struct s_cam) + 1)))
		return (0);
	return (cam);
}

void		setworld_cam(t_cam *cam, t_world *world)
{
	if (!cam)
		return ;
	cam->world = world;
	return ;
}

t_cam		*free_cam(t_cam *cam)
{
	if (cam)
	{
		if (cam->world)
			free_world(cam->world);
		ft_memdel((void **)&cam);
	}
	return (0);
}

void		set_cam(t_env *mlx, t_cam *cam)
{
	if (cam)
	{
		clear_img(mlx->img);
		if (mlx->cam)
			free_cam(mlx->cam);
		mlx->cam = cam;
	}
	return ;
}

