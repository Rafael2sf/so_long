/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:24:41 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/01 15:17:35 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl_bonus.h"

static char
	**sl_realloc_map(void *ptr, int cur_len, int new_len);

/* 
	Reads the map line by line, allocates SL_RLOC_M bytes,
	if map is bigger, then reallocates more SL_ROC_M  bytes
*/
char
	**sl_read_map(int fd)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * SL_RLOC_M);
	if (!map)
		return (NULL);
	i = 0;
	while (1)
	{
		map[i] = ft_getnl(fd);
		if (!map[i] && i == 0)
			sl_exitm(1, "Invalid map\n", NULL);
		if (!map[i])
			break ;
		i++;
		if (i != 0 && i % (SL_RLOC_M - 1) == 0)
			map = sl_realloc_map((void *)(map), i, i + SL_RLOC_M);
	}
	map[i] = NULL;
	return (map);
}

void
	sl_free_map(void *ptr)
{
	void	**map;
	int		i;

	map = (void **)(ptr);
	if (!map || !*map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

static char
	**sl_realloc_map(void *ptr, int cur_len, int new_len)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * new_len);
	if (!new)
	{
		sl_free_map(ptr);
		return (NULL);
	}
	while (i <= cur_len)
	{
		new[i] = ((char **)ptr)[i];
		i++;
	}
	while (i <= new_len)
	{
		new[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = new;
	return (new);
}
