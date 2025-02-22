/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:18:36 by maximart          #+#    #+#             */
/*   Updated: 2025/02/22 14:18:40 by maximart         ###   ########.fr       */
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