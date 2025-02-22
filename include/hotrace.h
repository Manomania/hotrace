/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:46 by maximart          #+#    #+#             */
/*   Updated: 2025/02/22 14:09:07 by maximart         ###   ########.fr       */
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
# define TABLE_SIZE		1000
# define BUFFER_SIZE	4096

/*******************************************************************************
*                                  Structures                                  *
*******************************************************************************/

typedef struct s_entry
{
	struct s_entry	*next;
	unsigned char	*key;
	int				value;
}					t_entry;

typedef struct s_table
{
	t_entry	*table[TABLE_SIZE];
}			t_table;

/*******************************************************************************
*                             Function Prototypes                              *
*******************************************************************************/

void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
