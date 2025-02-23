/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:22:46 by maximart          #+#    #+#             */
/*   Updated: 2025/02/23 18:30:39 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# include <stdio.h>

/*******************************************************************************
*                                    Macros                                    *
*******************************************************************************/

# define RESET		"\033[039m"
# define RED		"\033[091m"
# define GREEN		"\033[092m"
# define YELLOW		"\033[093m"

# define MSG_NOT_FND	": Not found."
# define BUFFER_SIZE	64
# define HASHMAP_POWER	10
# define HASHMAP_CHARGEFACTOR	0.7

/*******************************************************************************
*                                  Structures                                  *
*******************************************************************************/

typedef enum e_hash_status
{
	EMPTY,
	TOMBSTONE,
	OCCUPIED
}			t_hash_status;

typedef struct s_hash_entry
{
	unsigned long	key;
	void			*value;
	t_hash_status	status;
	size_t			probe_distance;
}					t_hash_entry;

typedef struct s_hashmap
{
	t_hash_entry	*table;
	size_t			size;
	int				count;
	double			charge_factor;
}			t_hashmap;

/*******************************************************************************
*                             Function Prototypes                              *
*******************************************************************************/

// src/hashmap/hashmap_managing.c
unsigned long	hash(char *str);
t_hashmap		*hashmap_new(int power, double chargefactor);
void			hashmap_free(t_hashmap *map, void (*del)(void *));

// src/hashmap/hashmap_methods.c
int				hashmap_resize(size_t new_size, t_hashmap *map);
void			*hashmap_search(unsigned long key, t_hashmap *map);
int				hashmap_insert(unsigned long key, void *value, t_hashmap *map);

// src/hashmap/memory_basics.c
void			ft_bzero(char *str);
void			*ft_calloc(size_t el_count, size_t el_size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memset(void *ptr, int value, size_t count);

// src/utils/string_basics.c
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);

// src/utils/string_basics2.c
void			delete_nl(char *str);
size_t			tmin(size_t m1, size_t m2);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// src/get_next_line.c
char			*get_next_line(int fd);
int				ft_check_line(char *str);
#endif
