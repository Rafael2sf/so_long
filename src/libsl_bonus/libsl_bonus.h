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

#ifndef LIBSL_BONUS_H
# define LIBSL_BONUS_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

/* Modifiers */
// Realloc multiplier for map reading 
# define SL_RLOC_M 5
// Delay between  movement
# ifndef DELAY
#  define DELAY 2000
# endif

/* Properties of app map */
typedef struct s_map
{
	char			**data;
	unsigned int	width;
	unsigned int	height;
	unsigned int	items;
	unsigned int	npcs;
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
	unsigned int	rot;
	unsigned int	steps;
	unsigned int	items;
}					t_ply;

/* npc variables */
typedef struct s_npc
{
	unsigned int	pos_x;
	unsigned int	pos_y;
	char			last_tile;
}					t_npc;

/* App properties and variables */
typedef struct s_app
{
	t_mlx	mlx;
	t_map	map;
	t_ply	ply;
	t_img	*tts;
	t_npc	*npc;
}			t_app;

/* Texture properties */
# define SL_TT_WIDTH 50
# define SL_TT_HEIGHT 50
# define SL_TT_COUNT 7

enum
{
	SL_TT_WALL,
	SL_TT_FLOOR,
	SL_TT_PLAYER_L,
	SL_TT_PLAYER_R,
	SL_TT_ITEM,
	SL_TT_EXIT,
	SL_TT_NPC
};
# define SL_TT_WALL_P "./content/textures/bonus/wall.xpm"
# define SL_TT_FLOOR_P "./content/textures/bonus/floor.xpm"
# define SL_TT_PLAYER_L_P "./content/textures/bonus/player_l.xpm"
# define SL_TT_PLAYER_R_P "./content/textures/bonus/player_r.xpm"
# define SL_TT_ITEM_P "./content/textures/bonus/item.xpm"
# define SL_TT_EXIT_P "./content/textures/bonus/exit.xpm"
# define SL_TT_NPC_P "./content/textures/bonus/npc.xpm"

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
char		**sl_read_map(int fd);
/* Verify if map is valid */
void		sl_parse_map(t_app *app);
/* Free the map */
void		sl_free_map(void *ptr);
/* Exit program clearing memory */
void		sl_exitm(int code, char *error, t_app *app);
/* New image form path */
t_img		sl_new_image(void *mlx, char *path);
/* Loads in the textures */
int			sl_parse_textures(t_app *app);
/* Initialise npc array */
void		sl_init_npcs(t_app *app);
/* List of textures is cleared */
void		sl_destroy_tt(t_app *app);
/* Set hooks */
int			sl_keybinds(int keycode, t_app *app);
/* Draw map */
void		sl_drawp_map(t_app *app);
/* Writes ascii text info to window */
void		sl_put_data(t_app *app);
/* if pressed moving key */
int			sl_ismove(int key);
/* Player moves */
void		sl_move(t_app *app, int keycode);
/* Update bot */
int			sl_npc_move(t_app *app);

#endif
