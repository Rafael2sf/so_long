/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:41:15 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 15:43:23 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

int	sl_move_up(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (app->map.data[y])
	{
		x = 0;
		while (app->map.data[y][x] != '\n')
		{
			if (app->map.data[y][x] == 'P')
			{
				if (app->map.data[y - 1][x] != '1')
				{
					app->map.data[y][x] = '0';
					app->map.data[y - 1][x] = 'P';
					return (1);
				}
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	sl_move_left(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (app->map.data[y])
	{
		x = 0;
		while (app->map.data[y][x] != '\n')
		{
			if (app->map.data[y][x] == 'P')
			{
				if (app->map.data[y][x - 1] != '1')
				{
					app->map.data[y][x] = '0';
					app->map.data[y][x - 1] = 'P';
					return (1);
				}
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);

}

int	sl_move_down(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (app->map.data[y])
	{
		x = 0;
		while (app->map.data[y][x] != '\n')
		{
			if (app->map.data[y][x] == 'P')
			{
				if (app->map.data[y + 1][x] != '1')
				{
					app->map.data[y][x] = '0';
					app->map.data[y + 1][x] = 'P';
					return (1);
				}
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	sl_move_right(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (app->map.data[y])
	{
		x = 0;
		while (app->map.data[y][x] != '\n')
		{
			if (app->map.data[y][x] == 'P')
			{
				if (app->map.data[y][x + 1] != '1')
				{
					app->map.data[y][x] = '0';
					app->map.data[y][x + 1] = 'P';
					return (1);
				}
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}
