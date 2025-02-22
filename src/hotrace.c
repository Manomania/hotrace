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

// unsigned long	hash(unsigned char *str)
// {
// 	unsigned long	hash;
// 	int				c;
//
// 	hash = 5381;
// 	c = 0;
// 	while (*str++)
// 		c = *str;
// 	while (*str++)
// 		hash = ((hash << 5) + hash) + c;
// 	return (hash);
// }

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

void	insert(t_table *table, unsigned char *key, char value)
{
	size_t index;
	t_entry *new_entry;

	new_entry = malloc(sizeof(t_entry));
	if (!new_entry)
		return;

	index = hash(key);
	new_entry->key = key;
	new_entry->value = (int)value;
	new_entry->next = table->table[index];
	table->table[index] = new_entry;
}

int	main(void)
{
	t_table			*table;
	size_t			i;
	unsigned char	*key;
	char			*value;

	table = malloc(sizeof(t_table));
	value = NULL;
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
	while (1)
	{
		key = (unsigned char *)read_line();
		if (!key || *key == '\0')
		{
			free(key);
			break ;
		}
		value = read_line();
		if (!value)
		{
			free(key);
			break;
		}
	}
	insert(table, key, *value);
	return (0);
}