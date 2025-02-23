/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_managing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:12:44 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 18:34:28 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hashmap	*hashmap_new(int power, double chargefactor)
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
	result->count = 0;
	result->charge_factor = chargefactor;
	return (result);
}

void	hashmap_free(t_hashmap *map, void (*del)(void *))
{
	size_t	index;

	if (del)
	{
		index = 0;
		while (index < map->size)
		{
			if (map->table[index].status == OCCUPIED)
				del(map->table[index].value);
			index++;
		}
	}
	if (map->table)
		free(map->table);
	free(map);
}

/*Murmur3hash*/
unsigned long	hash(char *str)
{
	unsigned long	hash;
	unsigned long	c;
	int				i;

	hash = 0x811c9dc5;
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned long)str[i];
		hash ^= c;
		hash *= 0x5bd1e995;
		hash ^= hash >> 15;
		i++;
	}
	return (hash);
}
