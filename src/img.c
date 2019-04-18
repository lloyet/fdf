/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 18:04:47 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:36:50 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_img		*free_img(void *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (0);
}

t_img		*new_img(void *mlx)
{
	t_img		*img;

	if (!(img = (struct s_img *)ft_memalloc(sizeof(struct s_img) + 1)))
		return (0);
	if (!(img->img = mlx_new_image(mlx, WIDTH, HEIGHT)))
		return (free_img(mlx, img));
	if (!(img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->sizeline, &img->endian)))
		return (free_img(mlx, img));
	img->bpp /= 8;
	return (img);
}

void		put_pixel_img(t_img *img, int x, int y, int color)
{
	if (!img || x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	*(int *)(img->img + ((x + y * WIDTH) * img->bpp)) = color;
	return ;
}

void		clear_img(t_img *img)
{
	ft_bzero(img->img, WIDTH * HEIGHT * img->bpp);
	return ;
}
