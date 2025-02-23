/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:51:15 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 02:59:42 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*c_pointer;
	size_t			index;

	c_pointer = (unsigned char *) pointer;
	index = 0;
	while (index < count)
	{
		c_pointer[index] = (unsigned char) value;
		index++;
	}
	return (pointer);
}

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

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}
