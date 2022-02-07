/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tt_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:46:00 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/07 16:47:54 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static void	sl_get_textures(t_app *app);

int	sl_parse_textures(t_app *app)
{
	int	i;

	(app->tts) = malloc(sizeof(t_img) * SL_TT_COUNT);
	if (!(app->tts))
		sl_exitm(3, strerror(errno), app);
	sl_get_textures(app);
	i = 0;
	while (i < SL_TT_COUNT)
	{
		if ((app->tts[i].ptr) == NULL)
			sl_exitm(4, "Failed to load textures\n", app);
		i++;
	}
	return (0);
}

void	sl_destroy_tt(t_app *app)
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

static void	sl_get_textures(t_app *app)
{
	app->tts[SL_TT_WALL] = sl_new_image(app->mlx.ptr, SL_TT_WALL_P);
	app->tts[SL_TT_FLOOR] = sl_new_image(app->mlx.ptr, SL_TT_FLOOR_P);
	app->tts[SL_TT_PLAYER_L] = sl_new_image(app->mlx.ptr, SL_TT_PLAYER_L_P);
	app->tts[SL_TT_PLAYER_R] = sl_new_image(app->mlx.ptr, SL_TT_PLAYER_R_P);
	app->tts[SL_TT_ITEM] = sl_new_image(app->mlx.ptr, SL_TT_ITEM_P);
	app->tts[SL_TT_EXIT] = sl_new_image(app->mlx.ptr, SL_TT_EXIT_P);
	app->tts[SL_TT_NPC] = sl_new_image(app->mlx.ptr, SL_TT_NPC_P);
}
