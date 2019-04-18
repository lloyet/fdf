/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 16:06:23 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:36:45 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH	1920
# define HEIGHT	1080

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../lib/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"
#include "get_next_line.h"

typedef struct		s_env
{
	void			*mlx;
	struct s_win	*win;
	struct s_img	*img;
	struct s_mouse	*mouse;
	struct s_cam	*cam;

}					t_env;

typedef struct		s_cam
{
	int				offset_x;
	int				offset_y;
	int				x;
	int				y;
	int				scale;
	struct s_world	*world;
}					t_cam;

typedef struct		s_win
{
	int				height;
	int				width;
}					t_win;

typedef struct		s_mouse
{
	char			key_isdown;
	int				x;
	int				y;
	int				last_x;
	int				last_y;
}					t_mouse;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_world
{
	int				min;
	int				max;
	int				size;
	struct s_vector	**vector_map;
}					t_world;

typedef struct		s_vector
{
	double				x;
	double				y;
	double				z;
	int				color;
}					t_vector;

t_env		*free_env(t_env *env);
t_env		*new_env(void);
t_cam		*new_cam(void);
t_cam		*free_cam(t_cam *cam);
t_img		*free_img(void *mlx, t_img *img);
t_img		*new_img(void *mlx);
t_world 	*new_world(int size);
t_world		*free_world(t_world *world);
t_world		*world_mapping(char *file);
t_vector	*new_vector(void);
t_vector	*rot_vector(t_vector *v, t_cam *c);
int			hook_mouseUP(int button, t_env *mlx);
int			hook_mouseDW(int buttonon, t_env *mlx);
int			hook_mousemove(int x, int y, t_env *mlx);
int			hook_keyboard(int key, t_env *mlx);
int			get_color(char *str);
int			map_sizing(char *file);
void		world_render(t_env *mlx);
void		setworld_cam(t_cam *cam, t_world *world);
void		put_pixel_img(t_img *img, int x, int y, int color);
void		clear_img(t_img *img);
void		init_vector(t_vector *v, double x, double y, double z, int color);
void		set_cam(t_env *mlx, t_cam *cam);
#endif
