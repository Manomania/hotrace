/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:42:49 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 02:58:57 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	ft_clean(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = 0;
}

int	ft_check_line(char	*str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str + i) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*line;
	int			read_byte;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (read_byte && ft_check_line(line) == 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
			return (ft_bzero(buffer), free(line), NULL);
		buffer[read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	ft_clean(buffer);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}
