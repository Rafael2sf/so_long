/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:57:38 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 12:58:53 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

t_img	sl_new_image(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	img.pixels  = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
									&img.line_size, &img.endian);
	return (img);
}
