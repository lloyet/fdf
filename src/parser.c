/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 17:54:00 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:36:44 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			map_sizing(char *file)
{
	int		size;
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	size = 0;
	while (get_next_line(fd, &line))
	{
		size += ft_strlen(*ft_strsplit(line, ' '));
		free(line);
	}
	close(fd);
	return (size);
}

t_world		*world_mapping(char *file)
{
	int			size;
	int			fd;
	int			x;
	int			y;
	int			z;
	char		*line;
	char		**split;
	t_world		*world;
	t_vector	*vector_map;

	
	y = 0;
	size = map_sizing(file);
	if (!(world = new_world(size)))
		return (0);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	world->min = 65535;
	world->max = -65535;
	vector_map = *world->vector_map;
	while (get_next_line(fd, &line))
	{
		x = 0;
		split = ft_strsplit(line, ' ');
		while (*split)
		{
			init_vector(vector_map = new_vector(), x++, y, z = ft_atoi(*split), get_color(*split));
			if (z < world->min)
				world->min = z;
			if (z > world->max)
				world->max = z;
			vector_map++;
			split++;
		}
		y++;
		free(line);
	}
	close(fd);
	return (world);
}
