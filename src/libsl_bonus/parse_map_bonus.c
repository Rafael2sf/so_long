/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:40:40 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/07 16:34:04 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static void
	sl_check_tile(t_app *app, unsigned int x, unsigned int y, int *has_exit);
static void	sl_check_format(t_app *app);

void	sl_parse_map(t_app *app)
{
	unsigned int	y;
	unsigned int	x;
	int				has_exit;

	y = 0;
	has_exit = 0;
	sl_check_format(app);
	while (app->map.data[y])
	{
		x = 0;
		while (app->map.data[y][x] && app->map.data[y][x] != '\n')
		{
			sl_check_tile(app, x, y, &has_exit);
			x++;
		}
		y++;
	}
	if (app->ply.pos_x == 0)
		sl_exitm(2, "Map does not contain a player start\n", app);
	if (has_exit == 0)
		sl_exitm(2, "Map does not contain a exit\n", app);
	if (app->map.items == 0)
		sl_exitm(2, "Map does not contain collectables\n", app);
}

static void	sl_check_format(t_app *app)
{
	unsigned int	y;
	unsigned int	len;
	unsigned int	len2;

	len = ft_strlen(app->map.data[0]);
	if (app->map.data[0][len - 1] == '\n')
		len--;
	y = 1;
	while (app->map.data[y])
	{
		len2 = ft_strlen(app->map.data[y]);
		if (app->map.data[y][len2 - 1] == '\n')
			len2--;
		if (len != len2)
			sl_exitm(2, "Map is not rectangular\n", app);
		y++;
	}
	(app->map.width) = len;
	(app->map.height) = y;
}

static void
	sl_check_tile(t_app *app, unsigned int x, unsigned int y, int *has_exit)
{
	if (((y == 0 || y == app->map.height - 1) && app->map.data[y][x] != '1')
		|| ((x == 0 || x == app->map.width - 1) && app->map.data[y][x] != '1'))
	{
		sl_exitm(2, "Map is not surrounded by walls\n", app);
	}
	else if (app->map.data[y][x] == 'P')
	{
		if (app->ply.pos_x != 0)
			sl_exitm(2, "More then one player spawn provided\n", app);
		(app->ply.pos_x) = x;
		(app->ply.pos_y) = y;
	}
	else if (app->map.data[y][x] == 'C')
		(app->map.items) += 1;
	else if (app->map.data[y][x] == 'E')
		(*has_exit) += 1;
	else if (app->map.data[y][x] == 'N')
		(app->map.npcs)++;
	else if (app->map.data[y][x] != '1' && app->map.data[y][x] != '0')
		sl_exitm(2, "Unknown map tile\n", app);
}
