/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:04:56 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/09 14:42:11 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

void	sl_exitm(int code, char *error, t_app *app)
{
	if (app)
	{
		if (app->map.data)
			sl_free_map(app->map.data);
		if (app->tts)
			sl_destroy_tt(app);
		if (app->mlx.win)
			mlx_destroy_window(app->mlx.ptr, app->mlx.win);
		if (app->npc)
			free(app->npc);
	}
	if (code != 0)
	{
		ft_putstr(STDERR_FILENO, "Error\n");
		ft_putstr(STDERR_FILENO, error);
	}
	exit(code);
}

t_img	sl_new_image(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

int	sl_ismove(int key)
{
	return (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D);
}
