/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:38:03 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/28 18:10:32 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

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

/* Delete later */
void	sl_show_stats(t_app *app)
{
	printf("map: {\n\tdata: \n");
	sl_print_map((const char **)app->map.data);
	printf(",\n\twidth: %u,\n\theight: %u,\n\titems: %u\n}\n",
		app->map.width, app->map.height, app->map.items);
	printf("player: {\n\tsteps: %u,\n\titems: %u, \n\tx: %u,\n\ty: %u\n}\n",
		app->ply.steps, app->ply.items, app->ply.pos_x, app->ply.pos_y);
}
