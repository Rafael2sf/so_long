/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:13:28 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/02 16:53:52 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static void
	sl_put_items(t_app *app, char **ptr);
static int
	sl_items_color(t_app *app);

void
	sl_put_data(t_app *app)
{
	char	*ptr[2];
	char	*steps;

	steps = ft_itoa(app->ply.steps);
	if (!steps)
		return ;
	mlx_string_put(app->mlx.ptr, app->mlx.win,
		((app->map.width * SL_TT_WIDTH) / 2), 5, 0x00FFFFFF, steps);
	free(steps);
	ptr[0] = ft_itoa(app->ply.items);
	if (!ptr[0])
		return ;
	ptr[1] = ft_itoa(app->map.items);
	if (!ptr[1])
	{
		free(ptr[0]);
		return ;
	}
	sl_put_items(app, (char **)ptr);
}

static void
	sl_put_items(t_app *app, char **ptr)
{
	size_t	len[2];
	char	*txt;

	len[0] = ft_strlen(ptr[0]);
	len[1] = ft_strlen(ptr[1]);
	txt = (char *)malloc(sizeof(char) * (len[0] + len[1] + 2));
	if (!txt)
	{
		free(ptr[0]);
		free(ptr[1]);
		return ;
	}
	ft_memcpy(txt, ptr[0], len[0]);
	free(ptr[0]);
	txt[len[0]] = '/';
	ft_memcpy(txt + len[0] + 1, ptr[1], len[1]);
	free(ptr[1]);
	txt[len[0] + len[1] + 1] = '\0';
	mlx_string_put(app->mlx.ptr, app->mlx.win, 5, 5, sl_items_color(app), txt);
	free(txt);
}

static int
	sl_items_color(t_app *app)
{
	if (app->map.items == app->ply.items)
		return (0x007FFF00);
	else if (app->ply.items > app->ply.items / 2)
		return (0x00FFFF00);
	else
		return (0x00FF0000);
}
