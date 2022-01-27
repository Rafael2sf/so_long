/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:06:13 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 17:22:55 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/libsl.h"

void	sl_init_vars(t_app *app)
{
	(app->vars.steps) = 0;
	(app->vars.inv) = 0;
	sl_verify_map((char **)app->map.data,
				&app->map.e_count, &app->map.p_count, &app->map.c_count);
	printf("%d %d %d\n", app->map.e_count, app->map.p_count, app->map.c_count);
}

int		main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		return (1);
	app.map.data = sl_read_map(argv[1], &app.map.width, &app.map.height);
	if (app.map.data == NULL)
		return (2);
	sl_init_vars(&app);
	app.mlx.ptr = mlx_init();
	app.mlx.win = mlx_new_window(app.mlx.ptr, app.map.width * SL_TILE_WIDTH,
								app.map.height * SL_TILE_HEIGHT, "so_long");
	sl_draw_map(app);
	mlx_key_hook(app.mlx.win, sl_hooks, &app);
	mlx_loop(app.mlx.ptr);
	return (0);
}
