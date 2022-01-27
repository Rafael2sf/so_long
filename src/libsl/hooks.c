/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:30:17 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 17:20:51 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

static void	sl_move(t_app *app, int keycode)
{
	int	ret;
	
	if (keycode == KEY_W)
		ret = sl_move_up(app);
	else if (keycode == KEY_A)
		ret = sl_move_left(app);
	else if (keycode == KEY_S)
		ret = sl_move_down(app);
	else if (keycode == KEY_D)
		ret = sl_move_right(app);
	else
		return ;
	if (ret != 0)
	{
		(app->vars.steps) += 1;
		printf("%d\n", app->vars.steps);
		mlx_clear_window(app->mlx.ptr, app->mlx.win);
		sl_draw_map(*app);
	}
}

int	sl_hooks(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		sl_free_map((void *)app->map.data);
		mlx_destroy_window(app->mlx.ptr, app->mlx.win);
		exit(0);
	}
	if (sl_ismove(keycode))
		sl_move(app, keycode);
	return (0);
}
