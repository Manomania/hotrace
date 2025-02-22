/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:18:50 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/22 18:14:30 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hashmap	*hashmap_new(int power, int chargefactor)
{
	t_hashmap	*result;

	result = malloc(sizeof(t_hashmap));
	if (!result)
		return (NULL);
	result->size = 1 << power;
	result->table = ft_calloc(result->size + 1, sizeof(t_hash_entry));
	if (!result->table)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int	hashmap_resize(size_t new_size, t_hashmap *map)
{
	t_hash_entry	*new_table;
	
	new_table =  ft_calloc(new_size + 1, sizeof(t_hash_entry));
	if (!new_table)
		return (0);
	return (1);
}

int	hashmap_insert(unsigned long key, void *value, t_hashmap *map)
{
	size_t	index;

	if ((double) map->count / map->size >= map->charge_factor)
	{
		if (!hashmap_resize(map->size << 1, map))
			return (0);
	}
	index = key & (map->size - 1);
	while (map->table[index].status != EMPTY && map->table[index].key != key)
		index = key & (map->size - 1);
	if (map->table[index].status == EMPTY)
		map->count++;
	map->table[index].key = key;
	map->table[index].status = OCCUPIED;
	map->table[index].value = value;
	return (1);
}

void	hashmap_free(t_hashmap *map, void (*del)(void *))
{
	int	index;
	
	if (del)
	{
		index = 0;
		while (index < map->size)
		{
			if (map->table[index].status == OCCUPIED
			|| map->table[index].status == DESTROYED)
				del(map->table[index].value);
			index++;
		}
	}
	if (map->table)
		free(map->table);
	free(map);
}
