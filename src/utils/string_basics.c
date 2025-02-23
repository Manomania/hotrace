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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	index;
	size_t	pre_size;

	if (!s1 || !s2)
		return (NULL);
	pre_size = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (pre_size + ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		temp[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		temp[pre_size + index] = s2[index];
		index++;
	}
	temp[pre_size + index] = '\0';
	return (temp);
}

static size_t	tmin(size_t m1, size_t m2)
{
	if (m1 > m2)
		return (m2);
	return (m1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;
	size_t	size;

	index = 0;
	size = ft_strlen(s);
	if (start >= size || s == NULL || len <= 0)
		return (ft_calloc(1, sizeof(char)));
	result = (char *)malloc(sizeof(char) * (tmin(size - start, len) + 1));
	if (!result)
		return (NULL);
	while (s[start + index] && index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
