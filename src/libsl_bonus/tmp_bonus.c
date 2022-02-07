/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:09:11 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/07 16:30:22 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

void	sl_print_map(const char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_putstr(STDOUT_FILENO, map[i]);
		i++;
	}
}

void	sl_show_stats(t_app *app)
{
	unsigned int	i;

	i = 0;
	printf("map: {\n\tdata: \n");
	sl_print_map((const char **)app->map.data);
	printf(",\n\twidth: %u,\n\theight: %u,\n\titems: %u\n}\n",
		app->map.width, app->map.height, app->map.items);
	printf("player: {\n\tsteps: %u,\n\titems: %u, \n\tx: %u,\n\ty: %u\n}\n",
		app->ply.steps, app->ply.items, app->ply.pos_x, app->ply.pos_y);
	if (app->npc)
	{
		printf("npcs: {\n");
		while (app->npc[i].pos_y > 0)
		{
			printf("\t%d.\ty: %d, x: %d\n",
				i, app->npc[i].pos_y, app->npc[i].pos_x);
			i++;
		}
		printf("}\n");
	}
}
