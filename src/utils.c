/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:18:36 by maximart          #+#    #+#             */
/*   Updated: 2025/02/22 17:28:07 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dest_data;
	unsigned const char		*src_data;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_data = (unsigned char *)dest;
	src_data = (unsigned const char *)src;
	while (i < n)
	{
		dest_data[i] = src_data[i];
		i++;
	}
	return (dest_data);
}

void	*ft_calloc(size_t el_count, size_t el_size)
{
	void	*temp;
	size_t	size;

	if (el_size == 0 || el_count == 0)
		return (malloc(0));
	if (el_count > __SIZE_MAX__ / el_size \
		|| el_size > __SIZE_MAX__ / el_count)
		return (NULL);
	size = el_count * el_size;
	temp = malloc(size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, size);
	return (temp);
}
