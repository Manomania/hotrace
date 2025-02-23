/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:34 by maximart          #+#    #+#             */
/*   Updated: 2025/02/23 18:41:01 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <asm-generic/errno-base.h>

static int	try_insert(unsigned long key, void *value, t_hashmap *map);
static int	read_key_value_pair(t_hashmap *map);
static int	read_searchs(t_hashmap *map);

int	main(void)
{
	t_hashmap	*map;

	map = hashmap_new(HASHMAP_POWER, HASHMAP_CHARGEFACTOR);
	if (!map)
		return (EXIT_FAILURE);
	if (!read_key_value_pair(map))
	{
		hashmap_free(map, free);
		return (EXIT_FAILURE);
	}
	if (!read_searchs(map))
	{
		hashmap_free(map, free);
		return (EXIT_FAILURE);
	}
	hashmap_free(map, free);
}

static int	read_key_value_pair(t_hashmap *map)
{
	int				next;
	char			*line;
	unsigned long	key;

	next = 0;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strlen(line) <= 1)
		{
			free(line);
			break ;
		}
		delete_nl(line);
		if (next == 0)
			key = hash(line);
		else if (next == 1 && !try_insert(key, line, map))
			return (0);
		if (next != 1)
			free(line);
		line = get_next_line(STDIN_FILENO);
		next = (next + 1) % 2;
	}
	return (next == 0);
}

static int	read_searchs(t_hashmap *map)
{
	char	*line;
	void	*result;

	result = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		delete_nl(line);
		result = hashmap_search(hash(line), map);
		if (!result)
		{
			printf("%s", line);
			write(1, line, ft_strlen(line));
			write(1, MSG_NOT_FND, 12);
		}
		else
			write(1, (char *)result, ft_strlen(result));
		write(1, "\n", 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

static int	try_insert(unsigned long key, void *value, t_hashmap *map)
{
	if (!hashmap_insert(key, value, map))
	{
		free(value);
		hashmap_free(map, free);
		return (0);
	}
	return (1);
}
