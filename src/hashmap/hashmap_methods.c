/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:18:50 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 04:04:22 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hashmap_resize(size_t new_size, t_hashmap *map)
{
	t_hash_entry	*new_table;
	size_t			index;
	size_t			hash_index;

	new_table =  ft_calloc(new_size + 1, sizeof(t_hash_entry));
	if (!new_table)
		return (0);
	index = 0;
	while (index < map->size)
	{
		if (map->table[index].status == OCCUPIED)
		{
			hash_index = map->table[index].key & (new_size - 1);
			while (new_table[hash_index].status == OCCUPIED)
				hash_index = (hash_index + 1) & (new_size - 1);
			new_table[hash_index] = map->table[index];
		}
		index++;
	}
	free(map->table);
	map->table = new_table;
	map->size = new_size;
	return (1);
}

int	hashmap_insert(unsigned long key, void *value, t_hashmap *map)
{
	size_t	index;

	if (!map)
		return (0);
	if ((double) map->count / map->size >= map->charge_factor)
	{
		if (!hashmap_resize(map->size << 1, map))
			return (0);
	}
	index = key & (map->size - 1);
	while (map->table[index].status != EMPTY && map->table[index].key != key)
		index = (index + 1) & (map->size - 1);
	if (map->table[index].status == EMPTY)
		map->count++;
	map->table[index].key = key;
	map->table[index].status = OCCUPIED;
	map->table[index].value = value;
	return (1);
}

void	*hashmap_search(unsigned long key, t_hashmap *map)
{
	size_t	index;
	size_t	start_index;

	index = key & (map->size - 1);
	start_index = index;
	while (map->table[index].status != EMPTY)
	{
		if (map->table[index].key == key)
		{
			return (map->table[index].value);
		}
		index = (index + 1) & (map->size - 1);
		if (index == start_index)
		{
			break;
		}
	}
	return (NULL);
}
