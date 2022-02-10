/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:06:13 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/09 16:42:51 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/libsl.h"

static int	sl_verify_params(int argc, char **argv);
static void	sl_init_app(t_app *app, int fd);
static int	sl_destroy_app(void *app);

int	main(int argc, char **argv)
{
	t_app	app;
	int		fd;

	fd = sl_verify_params(argc, argv);
	sl_init_app(&app, fd);
	close(fd);
	mlx_key_hook(app.mlx.win, sl_keybinds, &app);
	mlx_hook(app.mlx.win, ON_DESTROY, 0L, sl_destroy_app, &app);
	sl_drawp_map(&app);
	mlx_loop(app.mlx.ptr);
	return (0);
}

static int	sl_verify_params(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr(STDERR_FILENO, "Error\nUsage:\t./prog <map.ber>\n");
		exit(1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_putstr(STDERR_FILENO, "Error\nUnknown map file format\n");
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
	(app->mlx.ptr) = NULL;
	(app->mlx.win) = NULL;
	(app->map.items) = 0;
	(app->ply.items) = 0;
	(app->ply.steps) = 0;
	(app->map.data) = sl_read_map(fd);
	sl_parse_map(app);
	(app->mlx.ptr) = mlx_init();
	if ((app->mlx.ptr) == NULL)
		sl_exitm(3, "Mlx library error\n", app);
	(app->mlx.win) = mlx_new_window(app->mlx.ptr, SL_TT_WIDTH * app->map.width,
			SL_TT_HEIGHT * app->map.height, "so_long");
	if ((app->mlx.win) == NULL)
		sl_exitm(3, "Mlx library error\n", app);
	sl_parse_textures(app);
}

static int
	sl_destroy_app(void *app)
{
	sl_exitm(0, NULL, app);
	return (0);
}
