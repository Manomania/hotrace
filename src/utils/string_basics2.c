/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_basics2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:21:10 by maximart          #+#    #+#             */
/*   Updated: 2025/02/23 15:21:10 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

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

void	delete_nl(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (str[size - 1] == '\n')
		str[size - 1] = '\0';
}

size_t	tmin(size_t m1, size_t m2)
{
	if (m1 > m2)
		return (m2);
	return (m1);
}
