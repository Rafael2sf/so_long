/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:59:10 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/31 11:30:29 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"
/*
static void	sl_move_u(t_app *app);
static void	sl_move_l(t_app *app);
static void	sl_move_d(t_app *app);
static void	sl_move_r(t_app *app);*/
static void	sl_update_player(t_app *app, int y, int x);
/*
void	sl_move(t_app *app, int keycode)
{
	if (keycode == KEY_W)
		sl_move_u(app);
	else if (keycode == KEY_A)
		sl_move_l(app);
	else if (keycode == KEY_S)
		sl_move_d(app);
	else if (keycode == KEY_D)
		sl_move_r(app);
	if (app->map.data[app->ply.pos_y][app->ply.pos_x] == 'E')
		sl_exitm(0, NULL, app);
	mlx_clear_window(app->mlx.ptr, app->mlx.win);
	sl_drawp_map(app);
}
*/

void	sl_move(t_app *app, int keycode)
{
	if (keycode == KEY_W)
		sl_update_player(app, -1, 0);
	else if (keycode == KEY_A)
		sl_update_player(app, 0, -1);
	else if (keycode == KEY_S)
		sl_update_player(app, +1, 0);
	else if (keycode == KEY_D)
		sl_update_player(app, 0, +1);
	if (app->map.data[app->ply.pos_y][app->ply.pos_x] == 'E')
		sl_exitm(0, NULL, app);
	mlx_clear_window(app->mlx.ptr, app->mlx.win);
	sl_drawp_map(app);
}

static void	sl_update_player(t_app *app, int y, int x)
{
	if (app->map.data[app->ply.pos_y + y][app->ply.pos_x + x] == '1')
		return ;
	if (app->map.data[app->ply.pos_y + y][app->ply.pos_x + x] == 'E')
	{
		if (app->ply.items != app->map.items)
			return ;
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	else
	{
		if (app->map.data[app->ply.pos_y + y][app->ply.pos_x + x] == 'C')
				(app->ply.items += 1);
		(app->map.data[app->ply.pos_y + y][app->ply.pos_x + x]) = 'P';
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	(app->ply.pos_y) += y;
	(app->ply.pos_x) += x;
	(app->ply.steps) += 1;
	printf("%u\n", app->ply.steps);
}

/*
static void	sl_move_u(t_app *app)
{
	if (app->map.data[app->ply.pos_y - 1][app->ply.pos_x] == '1')
		return ;
	if (app->map.data[app->ply.pos_y - 1][app->ply.pos_x] == 'E')
	{
		if (app->ply.items != app->map.items)
			return ;
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	else
	{
		if (app->map.data[app->ply.pos_y - 1][app->ply.pos_x] == 'C')
				(app->ply.items += 1);
		(app->map.data[app->ply.pos_y - 1][app->ply.pos_x]) = 'P';
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	(app->ply.pos_y) -= 1;
	(app->ply.steps) += 1;
}

static void	sl_move_l(t_app *app)
{
	if (app->map.data[app->ply.pos_y][app->ply.pos_x - 1] == '1')
		return ;
	if (app->map.data[app->ply.pos_y][app->ply.pos_x - 1] == 'E')
	{
		if (app->ply.items != app->map.items)
			return ;
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	else
	{
		if (app->map.data[app->ply.pos_y][app->ply.pos_x - 1] == 'C')
				(app->ply.items += 1);
		(app->map.data[app->ply.pos_y][app->ply.pos_x - 1]) = 'P';
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	(app->ply.pos_x) -= 1;
	(app->ply.steps) += 1;
}

static void	sl_move_d(t_app *app)
{
	if (app->map.data[app->ply.pos_y + 1][app->ply.pos_x] == '1')
		return ;
	if (app->map.data[app->ply.pos_y + 1][app->ply.pos_x] == 'E')
	{
		if (app->ply.items != app->map.items)
			return ;
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	else
	{
		if (app->map.data[app->ply.pos_y + 1][app->ply.pos_x] == 'C')
				(app->ply.items += 1);
		(app->map.data[app->ply.pos_y + 1][app->ply.pos_x]) = 'P';
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	(app->ply.pos_y) += 1;
	(app->ply.steps) += 1;
}

static void	sl_move_r(t_app *app)
{
	if (app->map.data[app->ply.pos_y][app->ply.pos_x + 1] == '1')
		return ;
	if (app->map.data[app->ply.pos_y][app->ply.pos_x + 1] == 'E')
	{
		if (app->ply.items != app->map.items)
			return ;
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	else
	{
		if (app->map.data[app->ply.pos_y][app->ply.pos_x + 1] == 'C')
				(app->ply.items += 1);
		(app->map.data[app->ply.pos_y][app->ply.pos_x + 1]) = 'P';
		(app->map.data[app->ply.pos_y][app->ply.pos_x]) = '0';
	}
	(app->ply.pos_x) += 1;
	(app->ply.steps) += 1;
}
*/