/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 05:41:00 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 12:58:18 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector	*new_vector(void)
{
	t_vector	*v;

	if (!(v = (struct s_vector *)ft_memalloc(sizeof(struct s_vector) + 1)))
		return (0);
	v->color = 0xFFFFFFFF;
	return (v);
}

void		init_vector(t_vector *v, double x, double y, double z, int color)
{
	if (!v)
		return ;
	v->x = x;
	v->y = y;
	v->z = z;
	v->color = color;
	return ;
}

t_vector	*rot_vector(t_vector *v, t_cam *c)
{
	t_vector	*w;
	double			x;
	double			y;
	double			z;

	if (!(w = new_vector()))
		return (0);
	x = v->x;
	z = v->z;
	w->x = cos(c->y) * x + sin(c->y) * z;
	w->z = -sin(c->y) * x + cos(c->y) * z;
	y = v->y;
	z = w->z;
	w->y = cos(c->x) * y - sin(c->x) * z;
	w->z = sin(c->x) * y + cos(c->x) * z;
	w->color = v->color;
	return (w);
}
