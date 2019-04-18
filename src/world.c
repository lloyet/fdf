/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   world.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 08:49:21 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:36:49 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_world		*free_world(t_world *world)
{
	if (world)
	{
		if (world->vector_map)
			ft_memdel((void **)world->vector_map);
		ft_memdel((void **)&world);
	}
	return (0);
}

t_world		*new_world(int size)
{
	t_world		*world;

	if (!(world = (struct s_world *)ft_memalloc(sizeof(struct s_world) + 1)))
		return (0);
	world->min = 0;
	world->max = 0;
	world->size = size;
	if (!(world->vector_map = (struct s_vector **)ft_memalloc(sizeof(struct s_vector *)*size + 1)))
		return (free_world(world));
	return (world);
}

t_world		*fill_world(t_world *world)
{
	int		i;

	if (world->vector_map)
	{
		i = 0;
		while (i < (world->size))
		{
			i++;
		}
	}
	return (world);
}
