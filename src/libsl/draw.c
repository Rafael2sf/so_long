/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:55:24 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 15:28:55 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

void	sl_draw_square(t_app app, int x, int y, int color)
{
	t_img	img;
	int		a;
	int		b;
	
	img.ptr = mlx_new_image(app.mlx.ptr, SL_TILE_WIDTH, SL_TILE_HEIGHT);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
									&img.line_size, &img.endian);
	b = 0;
	while (b < SL_TILE_HEIGHT)
	{
		a = 0;
		while (a < SL_TILE_WIDTH)
		{
			sl_draw_pixel(&img, a, b, color);
			a++;
		}
		b++;
	}
	mlx_put_image_to_window(app.mlx.ptr, app.mlx.win, img.ptr, x, y);
}

void	sl_draw_extra(t_app app, t_img *imgs, int x, int y)
{
	mlx_put_image_to_window(app.mlx.ptr, app.mlx.win, imgs[1].ptr,
							x * SL_TILE_WIDTH, y * SL_TILE_HEIGHT);
	if (app.map.data[y][x] == 'P')
		sl_draw_square(app, x * SL_TILE_HEIGHT, y * SL_TILE_WIDTH, 0x0000FF00);
	else if (app.map.data[y][x] == 'E')
		sl_draw_square(app, x * SL_TILE_HEIGHT, y * SL_TILE_WIDTH, 0x000000FF);
	else if (app.map.data[y][x] == 'C')
		sl_draw_square(app, x * SL_TILE_HEIGHT, y * SL_TILE_WIDTH, 0x00FF00FF);
}

void	sl_draw_map(t_app app)
{
	t_img	imgs[2];
	int		x;
	int		y;
	
	imgs[0] = sl_new_image(app.mlx.ptr, "./content/textures/w.xpm");
	imgs[1] = sl_new_image(app.mlx.ptr, "./content/textures/f.xpm");
	y = 0;
	while (y < app.map.height)
	{
		x = 0;
		while (x < app.map.width)
		{
			if (app.map.data[y][x] == '1')
				mlx_put_image_to_window(app.mlx.ptr, app.mlx.win, imgs[0].ptr,
										x * SL_TILE_WIDTH, y * SL_TILE_HEIGHT);
			else
				sl_draw_extra(app, imgs, x, y);
			x++;
		}
		y++;
	}
	mlx_destroy_image(app.mlx.ptr, imgs[0].ptr);
	mlx_destroy_image(app.mlx.ptr, imgs[1].ptr);
}
