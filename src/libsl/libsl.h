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
# include <string.h>

/* Realloc multiplier for map reading */
# define SL_RLOC_M 5

/* Properties of app map */
typedef struct s_map
{
	char			**data;
	unsigned int	width;
	unsigned int	height;
	unsigned int	items;
}					t_map;

/* Properties of image for mlx */
typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

/* Mlx variables */
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

/* App player variables */
typedef struct s_ply
{
	unsigned int	pos_x;
	unsigned int	pos_y;
	unsigned int	steps;
	unsigned int	items;
}					t_ply;

/* App properties and variables */
typedef struct s_app
{
	t_mlx	mlx;
	t_map	map;
	t_ply	ply;
	t_img	*tts;
}			t_app;

/* Texture properties */
# define SL_TT_WIDTH 50
# define SL_TT_HEIGHT 50
# define SL_TT_COUNT 5

enum
{
	SL_TT_WALL,
	SL_TT_FLOOR,
	SL_TT_PLAYER,
	SL_TT_ITEM,
	SL_TT_EXIT
};
# define SL_TT_WALL_P "./content/textures/man/wall.xpm"
# define SL_TT_FLOOR_P "./content/textures/man/floor.xpm"
# define SL_TT_PLAYER_P "./content/textures/man/player.xpm"
# define SL_TT_ITEM_P "./content/textures/man/item.xpm"
# define SL_TT_EXIT_P "./content/textures/man/exit.xpm"

/* Mapping keys */
enum
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

/* Mapping events */
enum
{
	ON_DESTROY = 17
};

/* Reads map from a file */
char
	**sl_read_map(int fd);
/* Verify if map is valid */
void
	sl_parse_map(t_app *app);
/* Free the map */
void
	sl_free_map(void *ptr);
/* Exit program clearing memory */
void
	sl_exitm(int code, char *error, t_app *app);
/* New image form path */
t_img
	sl_new_image(void *mlx, char *path);
/* Loads in the textures */
int	
	sl_parse_textures(t_app *app);
/* List of textures is cleared */
void
	sl_destroy_tt(t_app *app);
/* Set hooks */
int	
	sl_keybinds(int keycode, t_app *app);
/* Draw map */
void
	sl_drawp_map(t_app *app);
/* if pressed moving key */
int	
	sl_ismove(int key);
/* Player moves */
void
	sl_move(t_app *app, int keycode);

#endif
