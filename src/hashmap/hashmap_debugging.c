/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_debugging.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:13:44 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/22 19:23:19 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	hashmap_print(t_hashmap *map)
{
	size_t	index;

	index = 0;
	while (index < map->size)
	{
		if (map->table[index].status == OCCUPIED)
			printf("|%lu : %s|", map->table[index].key, (char *)map->table[index].value);
		index++;
	}
}
