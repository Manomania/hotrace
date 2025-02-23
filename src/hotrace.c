/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:34 by maximart          #+#    #+#             */
/*   Updated: 2025/02/23 07:12:11 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <asm-generic/errno-base.h>

static int	try_insert(unsigned long key, void *value, t_hashmap *map);
static int	read_key_value_pair(t_hashmap *map);
static int	read_searchs(t_hashmap *map);
static void delete_nl(char *str);

int	main(void)
{
	t_hashmap	*map;

	map = hashmap_new(10, 0.7);
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
	while (line && ft_strlen(line) > 1)
	{
		delete_nl(line);
		if (next == 0)
			key = hash(line);
		if (next == 1)
		{
			if (!try_insert(key, line, map))
				return (EXIT_FAILURE);
			next = 0;
			line = get_next_line(STDIN_FILENO);
			continue ;
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
		next++;
	}
	free(line);
	return (next == 0);
}

static int	read_searchs(t_hashmap *map)
{
	char	*temp;
	char	*line;
	void	*result;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		delete_nl(line);
		result = hashmap_search(hash(line), map);
		if (!result)
		{
			temp = ft_strjoin(line, MSG_NOT_FND);
			if (!temp)
				return (free(line), 0);
			write(1, temp, ft_strlen(temp));
			free(temp);
		}
		else
			write(1, (char *) result, ft_strlen(result));
		write(1, "\n", 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

static void delete_nl(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (str[size - 1] == '\n')
		str[size - 1] = '\0';
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
