/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:51:15 by vdurand           #+#    #+#             */
/*   Updated: 2025/02/23 17:40:38 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdint.h>

void	*ft_memset(void *ptr, int value, size_t count)
{
	unsigned char	*p;
	unsigned char	val;
	uint64_t		val64;

	val = (unsigned char)value;
	p = ptr;
	while (((uintptr_t)p & 7) && count--)
		*p++ = val;
	val64 = (uint64_t)val | ((uint64_t)val << 8) | ((uint64_t)val << 16) \
	| ((uint64_t)val << 24) | ((uint64_t)val << 48) | ((uint64_t)val << 56);
	while (count >= 8)
	{
		*(uint64_t *)p = val64;
		p += 8;
		count -= 8;
	}
	while (count--)
		*p++ = val;
	return (ptr);
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
