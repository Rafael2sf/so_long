/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:24:41 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/27 15:23:29 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

#define SL_ALLOC_M 5

static char	**sl_realloc_map(void *ptr, int len);
static void sl_map_set(char **map, int *width, int *height);

char	**sl_read_map(char *path, int *width, int *height)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * SL_ALLOC_M);
	if (!map)
		return (NULL);
	i = 0;
	while (1)
	{
		map[i] = ft_getnl(fd);
		if (!map[i])
			break ;
		if (i != 0 && i % SL_ALLOC_M == 0)
			map = sl_realloc_map((void *)(map), i + SL_ALLOC_M + 1);
		if (map == NULL)
			return (NULL);
		i++;
	}
	map[i] = NULL;
	sl_map_set(map, width, height);
	return (sl_realloc_map((void *)(map), i));
}

void	sl_print_map(const char **map)
{
	int		i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_putstr(STDOUT_FILENO, map[i]);
		i++;
	}
	ft_putchar(STDOUT_FILENO ,'\n');
}

void	sl_free_map(void *ptr)
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

static char	**sl_realloc_map(void *ptr, int len)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * len);
	if (!new)
	{
		sl_free_map(ptr);
		return (NULL);
	}
	while (i <= len)
	{
		new[i] = ((char **)ptr)[i];
		i++;
	}	
	free(ptr);
	ptr = new;
	return (new);
}

static void sl_map_set(char **map, int *width, int *height)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	(*width) = ft_strlen(map[0]) - 1;
	(*height) = y;
}
