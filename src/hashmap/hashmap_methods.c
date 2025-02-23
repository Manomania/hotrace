/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:18:50 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 05:46:06 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/**
 * @brief Resizes the hashmap's internal table.
 *
 * Allocates a new table, rehashes existing entries, 
 * and uses linear probing 
 * for collisions. The table is expanded if the load 
 * factor threshold is exceeded.
 *
 * @param new_size The new table size.
 * @param map A pointer to the hashmap structure.
 * @return 1 if successful, 0 otherwise.
 */
int	hashmap_resize(size_t new_size, t_hashmap *map)
{
	t_hash_entry	*new_table;
	t_hash_entry	*old_table;
	size_t			old_size;
	size_t			index;

	new_table = ft_calloc(new_size, sizeof(t_hash_entry));
	if (!new_table)
		return (0);
	old_table = map->table;
	old_size = map->size;
	map->table = new_table;
	map->size = new_size;
	index = 0;
	while (index < old_size)
	{
		if (old_table[index].status == OCCUPIED)
			hashmap_insert(old_table[index].key, old_table[index].value, map);
		index++;
	}
	free(old_table);
	return (1);
}

static inline void	swap(t_hash_entry *a, t_hash_entry *b);

/**
 * @brief Inserts a key-value pair into the hashmap.
 *
 * If the key already exists, updates the value. 
 * Resizes the hashmap if the load factor 
 * exceeds the threshold. Linear probing resolves 
 * collisions with robin hood opti.
 *
 * @param key The key to insert.
 * @param value The associated value.
 * @param map A pointer to the hashmap structure.
 * @return 1 if successful, 0 on error.
 */
int	hashmap_insert(unsigned long key, void *value, t_hashmap *map)
{
	size_t			pos;
	t_hash_entry	last;

	if (!map)
		return (0);
	if ((double)(map->count + 1) / map->size >= map->charge_factor)
		if (!hashmap_resize(map->size << 1, map))
			return (0);
	pos = key & (map->size - 1);
	last = (t_hash_entry){.key = key, .value = value, \
		.status = OCCUPIED, .probe_distance = 0};
	while (1)
	{
		if (map->table[pos].status == EMPTY || map->table[pos].key == key)
		{
			if (map->table[pos].status == EMPTY)
				map->count++;
			map->table[pos] = last;
			return (1);
		}
		if (last.probe_distance > map->table[pos].probe_distance)
			swap(&last, &map->table[pos]);
		last.probe_distance++;
		pos = (pos + 1) & (map->size - 1);
	}
}

/**
 * @brief Searches for a key in the hashmap.
 *
 * Returns the value associated with the key, 
 * or NULL if the key is not found. 
 * Linear probing resolves collisions with robin hood opti.
 *
 * @param key The key to search for.
 * @param map A pointer to the hashmap structure.
 * @return The associated value, or NULL if not found.
 */
void	*hashmap_search(unsigned long key, t_hashmap *map)
{
	size_t	pos;
	size_t	dist;

	dist = 0;
	pos = key & (map->size - 1);
	while (map->table[pos].status != EMPTY)
	{
		if (map->table[pos].key == key)
			return (map->table[pos].value);
		if (dist > map->table[pos].probe_distance)
			return (NULL);
		pos = (pos + 1) & (map->size - 1);
		dist++;
	}
	return (NULL);
}

static inline void	swap(t_hash_entry *a, t_hash_entry *b)
{
	t_hash_entry	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
