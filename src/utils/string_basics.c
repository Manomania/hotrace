/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 03:02:24 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 03:07:42 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (!s)
		return (NULL);
	chr = (char) c;
	while (*s != '\0')
	{
		if (*s == chr)
			return ((char *) s);
		s++;
	}
	if (chr == '\0')
		return ((char *) s);
	return (NULL);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dest)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = 0;
	while (s2[len_s2] != '\n' && s2[len_s2] != 0)
		len_s2++;
	if (s2[len_s2] == '\n')
		len_s2++;
	join = malloc(len_s1 + len_s2 + 1);
	if (!join)
		return (free(s1), NULL);
	if (s1)
		ft_strlcpy(join, s1, len_s1 + 1);
	ft_strlcpy(join + len_s1, s2, len_s2 + 1);
	free(s1);
	return (join);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	while (s[s_len] != '\n' && s[s_len] != 0)
		s_len++;
	if (s[s_len] == '\n')
		s_len++;
	dup = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
