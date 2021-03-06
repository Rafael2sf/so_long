/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_npc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:38:29 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/07 16:33:05 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static void	sl_map_npcs(t_app *app, unsigned int *i);

void	sl_init_npcs(t_app *app)
{
	unsigned int	i;

	if (app->map.npcs < 1)
		return ;
	(app->npc) = malloc(sizeof(t_npc) * (app->map.npcs + 1));
	if (!app->npc)
		sl_exitm(4, strerror(errno), app);
	i = 0;
	sl_map_npcs(app, &i);
	if (i == 0)
	{
		free(app->npc);
		(app->npc) = NULL;
	}
	app->npc[i].pos_y = 0;
}

static void	sl_map_npcs(t_app *app, unsigned int *i)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			if (app->map.data[y][x] == 'N')
			{
				(app->npc[*i].pos_y) = y;
				(app->npc[*i].pos_x) = x;
				(app->npc[*i].last_tile) = '0';
				(*i)++;
			}
			x++;
		}
		y++;
	}
}
