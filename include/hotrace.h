/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:46 by maximart          #+#    #+#             */
/*   Updated: 2025/02/23 04:30:48 by vdurand          ###   ########.fr       */
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

# define GNL_BUFFER_SIZE	1024

/*******************************************************************************
*                                  Structures                                  *
*******************************************************************************/

typedef enum	e_hash_status
{
	EMPTY,
	TOMBSTONE,
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
	size_t			size;
	int				count;
	double			charge_factor;
}			t_hashmap;

/*******************************************************************************
*                             Function Prototypes                              *
*******************************************************************************/

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t el_count, size_t el_size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *pointer, int value, size_t count);

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*get_next_line(int fd);

t_hashmap	*hashmap_new(int power, double chargefactor);
int			hashmap_insert(unsigned long key, void *value, t_hashmap *map);
int			hashmap_resize(size_t new_size, t_hashmap *map);
void		hashmap_free(t_hashmap *map, void (*del)(void *));
void		*hashmap_search(unsigned long key, t_hashmap *map);

void		hashmap_print(t_hashmap *map);
#endif
