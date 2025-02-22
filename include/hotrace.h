/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:46 by maximart          #+#    #+#             */
/*   Updated: 2025/02/22 18:23:17 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include <stdio.h>

/*******************************************************************************
*                                    Macros                                    *
*******************************************************************************/

# define RESET		"\033[039m"
# define RED		"\033[091m"
# define GREEN		"\033[092m"
# define YELLOW		"\033[093m"

# define MSG_NOT_FND	": Not found.\n"
# define BUFFER_SIZE	4096

/*******************************************************************************
*                                  Structures                                  *
*******************************************************************************/

typedef enum	e_hash_status
{
	EMPTY,
	DESTROYED,
	OCCUPIED
}			t_hash_status;

typedef struct	s_hash_entry
{
	unsigned long	key;
	void			*value;
	t_hash_status	status;
}					t_hash_entry;

typedef struct	s_hashmap
{
	t_hash_entry	*table;
	int				size;
	int				count;
	double			charge_factor;
}			t_hashmap;

/*******************************************************************************
*                             Function Prototypes                              *
*******************************************************************************/

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t el_count, size_t el_size);

#endif
