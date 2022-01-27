/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:04:56 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 17:16:16 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

void	sl_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		sl_ismove(int key)
{
	return ((key == 13 || key == 0 || key == 1 || key == 2));
}

int		sl_verify_map(char **map, int *e_count, int *p_count, int *c_count)
{
	int	x;
	int	y;

	(*p_count) = 0;
	(*c_count) = 0;
	(*e_count) = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
				(*p_count) += 1;
			else if (map[y][x] == 'C')
				(*c_count) += 1;
			else if (map[y][x] == 'E')
				(*e_count) += 1;
			else if (map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
