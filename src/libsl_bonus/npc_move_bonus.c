/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:45:52 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/02 16:56:48 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static void
	sl_npc_up(t_app *app, int i);

int
	sl_npc_move(t_app *app)
{
	static int	delay;
	int			i;

	if (++delay != DELAY)
		return (0);
	delay = 0;
	i = 0;
	if (!app->npc)
		return (0);
	while (app->npc[i].pos_y != 0)
		sl_npc_up(app, i++);
	mlx_clear_window(app->mlx.ptr, app->mlx.win);
	sl_drawp_map(app);
	if (app->map.data[app->ply.pos_y][app->ply.pos_x] != 'P')
		sl_exitm(0, NULL, app);
	return (1);
}

static void
	sl_npc_up(t_app *app, int i)
{
	if ((app->map.data[app->npc[i].pos_y - 1][app->npc[i].pos_x]) == '1')
	{
		(app->map.data[app->npc[i].pos_y][app->npc[i].pos_x]) = '0';
		(app->npc[i].pos_y) = (app->map.height - 1);
		(app->npc[i].last_tile) = '1';
	}
	else
	{
		(app->map.data[app->npc[i].pos_y][app->npc[i].pos_x])
			= app->npc[i].last_tile;
		(app->npc[i].last_tile)
			= (app->map.data[app->npc[i].pos_y - 1][app->npc[i].pos_x]);
		(app->map.data[app->npc[i].pos_y - 1][app->npc[i].pos_x]) = 'N';
		(app->npc[i].pos_y) -= 1;
	}
}
