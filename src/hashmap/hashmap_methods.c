/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:18:50 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 04:35:07 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/**
 * @brief Resizes the hashmap to a new size.
 *
 * This function resizes the hashmap's internal table 
 * to a new size by reallocating memory.
 * and rehashing existing entries into the new table. 
 * It uses linear probing to handle collisions.
 * The table is expanded when the number of entries 
 * exceeds a load factor threshold.
 *
 * @param new_size The new size for the hashmap's internal table.
 * @param map A pointer to the hashmap structure.
 * @return 1 if resizing was successful, 0 otherwise.
 */
int	hashmap_resize(size_t new_size, t_hashmap *map)
{
	t_hash_entry	*new_table;
	size_t			index;
	size_t			hash_index;

	new_table = ft_calloc(new_size + 1, sizeof(t_hash_entry));
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

/**
 * @brief Inserts a key-value pair into the hashmap.
 *
 * This function inserts a new key-value pair into the hashmap. 
 * If the key already exists, the value is updated. 
 * The hashmap is resized automatically when the load factor exceeds the 
 * specified charge factor. It uses linear probing to resolve collisions.
 *
 * @param key The key to be inserted.
 * @param value The value associated with the key.
 * @param map A pointer to the hashmap structure.
 * @return 1 if the insertion was successful, 0 if an error occurred.
 */
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

/**
 * @brief Searches for a value associated with a key in the hashmap.
 *
 * This function searches the hashmap for the specified key. If the key is found,
 * the associated value is returned. If the key is not present, NULL is returned.
 * Linear probing is used to handle collisions.
 *
 * @param key The key to be searched for.
 * @param map A pointer to the hashmap structure.
 * @return A pointer to the value associated with the key, or NULL if not found.
 */
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
			break ;
		}
	}
	return (NULL);
}
