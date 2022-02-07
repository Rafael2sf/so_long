/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:04 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/07 16:34:47 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

static void	sl_put_texture(t_app *app, int x, int y);

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
}

static void	sl_put_texture(t_app *app, int x, int y)
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
}
