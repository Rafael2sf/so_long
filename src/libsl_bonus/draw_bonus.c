/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:54:12 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/31 18:06:00 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static int
	sl_diff(int a, int b, int diff);

static void
	sl_put_texture(t_app *app, int x, int y);
	
void
	sl_drawp_map(t_app *app)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			if (sl_diff(app->ply.pos_x, x, SL_VIEW_DEPTH) 
			&& sl_diff(app->ply.pos_y, y, SL_VIEW_DEPTH))
				sl_put_texture(app, x, y);
			x++;
		}
		y++;
	}
}

static void
	sl_put_texture(t_app *app, int x, int y)
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
		mlx_put_image_to_window(app->mlx.ptr, app->mlx.win,
			app->tts[SL_TT_PLAYER].ptr,
			x * SL_TT_WIDTH, y * SL_TT_HEIGHT);
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

static int
	sl_diff(int a, int b, int diff)
{
	return (diff <= 0 || ((a - b) <= diff && -(a - b) <= diff));
}
