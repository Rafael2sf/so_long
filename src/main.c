/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:06:13 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/26 17:57:18 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/libsl.h"

int		main(void)
{
	t_map	map;

	map.map = sl_read_map("map.ber", &map.width, &map.height);
	if (map.map == NULL)
		perror("");
	printf("%d -- %d\n", map.width, map.height);
	sl_print_map((const char **)map.map);
	sl_free_map((void *)(map.map));
	return (0);
}
