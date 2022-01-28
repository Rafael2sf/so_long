/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:06:13 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/28 18:16:26 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/libsl.h"

static int	sl_verify_params(int argc, char **argv);
static void	sl_init_app(t_app *app, int fd);

int	main(int argc, char **argv)
{
	t_app	app;
	int		fd;

	fd = sl_verify_params(argc, argv);
	sl_init_app(&app, fd);
	close(fd);
	mlx_key_hook(app.mlx.win, sl_hooks, &app);
	sl_drawp_map(&app);
	mlx_loop(app.mlx.ptr);
	return (0);
}

static int	sl_verify_params(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr(STDERR_FILENO, "Error\nMissing map file.\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(STDERR_FILENO, "Error\n");
		perror(argv[1]);
		exit(1);
	}
	return (fd);
}

static void	sl_init_app(t_app *app, int fd)
{
	(app->tts) = NULL;
	(app->map.data) = NULL;
	(app->mlx.ptr) = mlx_init();
	if ((app->mlx.ptr) == NULL)
		sl_exitm(3, "Mlx library error\n", app);
	(app->map.data) = sl_read_map(fd);
	(app->map.items) = 0;
	(app->ply.items) = 0;
	(app->ply.steps) = 0;
	sl_parse_map(app);
	sl_parse_textures(app);
	(app->mlx.win) = mlx_new_window(app->mlx.ptr, SL_TT_WIDTH * app->map.width,
			SL_TT_HEIGHT * app->map.height, "so_long");
	if ((app->mlx.win) == NULL)
		sl_exitm(3, "Mlx library error\n", app);
}
