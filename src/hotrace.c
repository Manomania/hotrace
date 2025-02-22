/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:34 by maximart          #+#    #+#             */
/*   Updated: 2025/02/22 10:22:37 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <asm-generic/errno-base.h>

unsigned long	hash(const unsigned char *str)
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
	size_t	i;
	char	c;
	char	ret;

}

int	main(void)
{
	t_table	*table;
	size_t	i;

	table = malloc(sizeof(t_table));
	if (!table)
	{
		printf(RED"Error:\n%s\n"RESET, strerror(ENOMEM));
		return (1);
	}
	i = 0;
	while (i < TABLE_SIZE)
	{
		table->table[i] = NULL;
		i++;
	}
	return (0);
}