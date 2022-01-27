/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:24:00 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/26 15:24:00 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSL_H
# define LIBSL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define SL_TILE_WIDTH 50
# define SL_TILE_HEIGHT 50

typedef	struct s_map
{
	char	**data;
	int		width;
	int		height;
	int		p_count;
	int		c_count;
	int		e_count;
}			t_map;

typedef struct	s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_vars
{
	int		steps;
	int		inv;
}			t_vars;

typedef	struct s_app
{
	t_mlx	mlx;
	t_map	map;
	t_vars	vars;
}			t_app;

enum
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

void	sl_draw_pixel(t_img *img, int x, int y, int color);
t_img	sl_new_image(void *mlx, char *path);

char	**sl_read_map(char *path, int *width, int *height);
int		sl_verify_map(char **map, int *e_count, int *p_count, int *c_count);
void	sl_print_map(const char **map);
void	sl_draw_map(t_app app);
void	sl_free_map(void *ptr);

int		sl_hooks(int keycode, t_app *app);
int		sl_move_up(t_app *app);
int		sl_move_left(t_app *app);
int		sl_move_down(t_app *app);
int		sl_move_right(t_app *app);

int		sl_ismove(int key);

#endif
