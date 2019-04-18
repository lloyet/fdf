/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 16:05:47 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/24 02:23:19 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./inc/fdf.h"

void	print_dot(t_dot *dot, int i)
{
	printf("------\ndot_%i\nAddr = %p\ndot->x = %i\ndot->y = %i\ndot->value = %i\ndot->color = 0x%08x\n", i, dot, dot->x, dot->y, dot->value, dot->color);
	return ;
}

int		main(int argc, char **argv)
{
	t_dot *world;
	t_dot *save;
	int fd;
	int i;

	i = 0;
	argc = 1*argc;
	if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	world = file_parsing(fd);
	while (world)
	{
		save = world;
		world = world->next;
		print_dot(save, i++);
		free(save);
	}
	free_world(world);
	close(fd);
	return (0);
}
