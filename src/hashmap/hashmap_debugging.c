/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_debugging.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:13:44 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 03:45:05 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	hashmap_print(t_hashmap *map)
{
	size_t	index;

	index = 0;
	printf("\nHASHMAP:\n");
	while (index < map->size)
	{
		if (map->table[index].status == OCCUPIED)
			printf("|%zu| %zu : %s|\n", index, map->table[index].key, (char *)map->table[index].value);
		index++;
	}
}
