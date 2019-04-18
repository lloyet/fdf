/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 18:41:24 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 06:48:40 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*void		draw_line(t_dot *dot1, t_dot *dot2, void *mlx, void *window)
{
	int	y;
	int	x;
	int dx;
	int dy;
	int coef;

	dx = dot2->matrix->x - dot1->matrix->x;
	dy = dot2->matrix->y - dot1->matrix->y;
	x = dot1->matrix->x;
	y = dot1->matrix->y;
	coef = dx - 2*dy;
	while (x <= dx)
	{
		mlx_pixel_put(mlx, window, x, y, dot1->color);
		if (coef < 0)
		{
			coef = coef + 2*dx;
			y++;
		}
		coef = coef - 2*dy;
		x++;
	}
	return ;
}*/	
