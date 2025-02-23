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

// static size_t	bufcpy(char *dest, const char *src)
// {
// 	size_t	index;
//
// 	index = 0;
// 	while (src[index])
// 	{
// 		dest[index] = src[index];
// 		index++;
// 	}
// 	while (index < GNL_BUFFER_SIZE)
// 	{
// 		dest[index] = '\0';
// 		index++;
// 	}
// 	dest[index] = '\0';
// 	return (index);
// }
//
// static size_t	iuntilchar(char *str, char c)
// {
// 	size_t	index;
//
// 	index = 0;
// 	while (str[index] && str[index] != c)
// 		index++;
// 	if (str[index] == c)
// 		index++;
// 	return (index);
// }
//
// static char	*ft_join_nline(char *s1, char *s2)
// {
// 	char	*result;
//
// 	if (!s1)
// 	{
// 		s1 = malloc(sizeof(char));
// 		if (s1 == NULL)
// 		{
// 			return (NULL);
// 		}
// 		s1[0] = '\0';
// 	}
// 	result = ft_strjoin(s1, s2);
// 	if (ft_strchr(s2, '\n') == NULL)
// 		ft_bzero(s2, ft_strlen(s2));
// 	free(s1);
// 	if (!result)
// 		return (NULL);
// 	return (result);
// }
//
// char	*get_next_line(int fd)
// {
// 	static char		buffer[GNL_BUFFER_SIZE + 1];
// 	ssize_t			readed;
// 	char			*line;
// 	char			*res;
//
// 	line = NULL;
// 	while (ft_strchr(line, '\n') == NULL)
// 	{
// 		if (buffer[0] == '\0')
// 		{
// 			readed = read(fd, buffer, GNL_BUFFER_SIZE);
// 			if (readed == -1)
// 				return (free(line), NULL);
// 			if (readed == 0)
// 				return (line);
// 		}
// 		line = ft_join_nline(line, buffer);
// 		if (!line)
// 			return (NULL);
// 	}
// 	res = ft_substr(line, 0, iuntilchar(line, '\n'));
// 	free(line);
// 	if (!res)
// 		return (NULL);
// 	return (bufcpy(buffer, buffer + iuntilchar(buffer, '\n')), res);
// }

/*  int	main(void)
 {
 	int fd = open("1char.txt", O_RDONLY);
 	char *test;
 	test = get_next_line(fd); 
 	printf("line = '%s'\n", test);
 	free(test);
 	while (test != NULL)
 	{
 		test = get_next_line(fd); 
 		printf("line = '%s'\n", test);
 		free(test);
 	}
 	close(fd);
 }  */