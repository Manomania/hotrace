/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:34 by maximart          #+#    #+#             */
/*   Updated: 2025/02/23 04:25:07 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <asm-generic/errno-base.h>

unsigned long	hash(char *str)
{
	unsigned long	hash;
	int				c;
	int				i;

	hash = 5381;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		hash = ((hash << 5) + hash) + c;
		i++;
	}
	return (hash);
}

static int	try_insert(char *key, void *value, t_hashmap *map)
{
	if (!hashmap_insert(hash(key), value, map))
	{
		free(key);
		hashmap_free(map, NULL);
		return (0);
	}
	hashmap_print(map);
	return (1);
}

int	main(void)
{
	t_hashmap	*test;
	char		*text;

	test = hashmap_new(2, 0.7);
	if (!test)
		return (EXIT_FAILURE);
	text = get_next_line(STDIN_FILENO);
	while (text)
	{
		// On enleve le /n pour que ca puisse chercher pas necessaire
		text[ft_strlen(text) - 1] = '\0';
		if (!try_insert(text, "Test", test))
			return (EXIT_FAILURE);
		free(text);
		text = get_next_line(STDIN_FILENO);
		
	}
	printf("\n RESULT : %s\n%zu", (char *) hashmap_search(hash("Dino"), test), hash("Dino"));
	hashmap_free(test, NULL);
}
