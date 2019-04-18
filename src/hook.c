/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 15:59:07 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 07:25:05 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
 * MOUSE CONFIG:
 * 1 -> LEFT BUTTON
 * 2 -> RIGHT BUTTTON
 * 3 -> SCROLL BUTTON
 * 4 | 6 -> SCROLL UP
 * 5 | 7 -> SCROLL DOWN
 * */

int			hook_mouseUP(int button, t_env *mlx)
{
	mlx->mouse->key_isdown &= ~(1 << button);
	return (0);
}

int			hook_mouseDW(int button, t_env *mlx)
{
	mlx->mouse->key_isdown |= 1 << button;
	return (0);
}

int			hook_mousemove(int x, int y, t_env *mlx)
{
	t_mouse *mouse;

	mouse = mlx->mouse;
	mouse->last_x = mouse->x;
	mouse->x = x;
	mouse->last_y = mouse->y;
	mouse->y = y;
	if (mouse->key_isdown & (1 << 1) || mouse->key_isdown & (1 << 2))//rotate
	{
		mlx->cam->x += (mouse->last_y - y) / 200.0f;
		mlx->cam->y -= (mouse->last_x - x) / 200.0f;
	}
	else if (mouse->key_isdown & (1 << 2))//zoom in out
	{
		mlx->cam->scale += (mouse->last_y - y) / 10.0f + 0.5f;
			if (mlx->cam->scale < 1)
				mlx->cam->scale = 1;
	}
	else if (mouse->key_isdown & (1 << 3))//move
	{
		mlx->cam->offset_x += (x - mouse->last_x);
		mlx->cam->offset_y += (y - mouse->last_y);
	}
	if (mouse->key_isdown)
		world_render(mlx);
	return (0);
}

int			hook_keyboard(int key, t_env *mlx)
{
	mlx = mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
