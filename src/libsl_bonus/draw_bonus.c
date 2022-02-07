/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:54:12 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/07 16:32:52 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static int	sl_diff(int a, int b, int diff);
static void	sl_put_texture(t_app *app, unsigned int x, unsigned int y);
static void	sl_draw_player(t_app *app, unsigned int x, unsigned int y);	

void	sl_drawp_map(t_app *app)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			sl_put_texture(app, x, y);
			x++;
		}
		y++;
	}
	sl_put_data(app);
}

static void	sl_put_texture(t_app *app, unsigned int x, unsigned int y)
{
	if (app->map.data[y][x] == '1')
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_WALL].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
	else if (app->map.data[y][x] == '0')
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_FLOOR].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
	else if (app->map.data[y][x] == 'P')
		sl_draw_player(app, x, y);
	else if (app->map.data[y][x] == 'C')
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_ITEM].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
	else if (app->map.data[y][x] == 'E')
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_EXIT].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
	else if (app->map.data[y][x] == 'N')
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_NPC].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
}

static void	sl_draw_player(t_app *app, unsigned int x, unsigned int y)
{
	if ((app->ply.rot) == 0)
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_PLAYER_R].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
	else
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_PLAYER_L].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
}
