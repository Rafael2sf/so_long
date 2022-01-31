/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:39:17 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/31 18:18:10 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

int
	sl_parse_textures(t_app *app)
{
	int	i;

	(app->tts) = malloc(sizeof(t_img) * SL_TT_COUNT);
	if (!(app->tts))
		sl_exitm(3, strerror(errno), app);
	app->tts[SL_TT_WALL] = sl_new_image(app->mlx.ptr,
			"./content/textures/w.xpm");
	app->tts[SL_TT_FLOOR] = sl_new_image(app->mlx.ptr,
			"./content/textures/f.xpm");
	app->tts[SL_TT_PLAYER] = sl_new_image(app->mlx.ptr,
			"./content/textures/p.xpm");
	app->tts[SL_TT_ITEM] = sl_new_image(app->mlx.ptr,
			"./content/textures/i.xpm");
	app->tts[SL_TT_EXIT] = sl_new_image(app->mlx.ptr,
			"./content/textures/e.xpm");
	i = 0;
	while (i < SL_TT_COUNT)
	{
		if ((app->tts[i].ptr) == NULL)
			sl_exitm(4, "Failed to load textures\n", app);
		i++;
	}
	return (0);
}

void
	sl_destroy_tt(t_app *app)
{
	int	i;

	i = 0;
	while (i < SL_TT_COUNT)
	{
		if (app->tts[i].ptr != NULL)
			mlx_destroy_image(app->mlx.ptr, app->tts[i].ptr);
		i++;
	}
	free(app->tts);
	(app->tts) = NULL;
}
