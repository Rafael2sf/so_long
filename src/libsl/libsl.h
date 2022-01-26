/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:24:00 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/26 15:24:00 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSL_H
# define LIBSL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define SL_IMG_SIZE 50

typedef	struct s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;

char	**sl_read_map(char *path, int *width, int *height);
void	sl_print_map(const char **map);
void	sl_free_map(void *ptr);

#endif
