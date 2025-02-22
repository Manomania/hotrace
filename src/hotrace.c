/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:34 by maximart          #+#    #+#             */
/*   Updated: 2025/02/22 19:01:44 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <asm-generic/errno-base.h>

unsigned long	hash(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	c = 0;
	while (*str++)
		c = *str;
	while (*str++)
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

char	*read_line(void)
{
	int			ret;
	int			i;
	char		*line;
	char		buffer[BUFFER_SIZE];
	char		c;

	i = 0;
	ret = 1;
	c = 0;
	while (ret > 0 && c != '\n')
	{
		ret = read(0, &c, 1);
		if (i < BUFFER_SIZE - 1)
			buffer[i++] = c;
		if (ret <= 0 && i == 0)
			return (NULL);
	}
	buffer[i] = '\0';
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i + 1);
	return (line);
}

int	main(void)
{
	t_hashmap	*test;

	test = hashmap_new(4, 0.7);
	hashmap_insert(hash("Bonjour"), "OUIII", test);

	hashmap_free(test, NULL);
}
