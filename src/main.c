/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 02:24:04 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:36:47 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int argc, char **argv)
{
	/*void	*mlx;
	void	*window;
	int		fd;
	int		i;
	int		c;

	c = 3;
	i = 0;
	argc = 1*argc;
	if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "fdf");
	world = file_parsing(fd);
	while (world)
	{
		save = world;
		world = world->next;
		if (world)
			draw_line(save, world, mlx, window);
		free(save);
	}
	mlx_hook(window, 3, 0, hook_keyboard, mlx);
	mlx_hook(window, 4, 0, hook_mouseDW, mlx);
	mlx_hook(window, 5, 0, hook_mouseUP, mlx);
	mlx_loop(mlx);*/
	argc = 1*argc;
	printf("%i", map_sizing(argv[1]));
	return (0);
}
