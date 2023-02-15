#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>


// ft_split
char	**ft_split(const char *s, char c);
void	allocate_split(const char *s, char **str, char c, size_t allocated_size);
int	allc_or_free(const char *s, char **str, size_t s_i, int indexes[]);
void	free_mem(char **str, size_t length);
size_t	count_allocate_size(const char *s, char c);

// ft_atoi
int	ft_atoi(const char *str);
int	ispace(char space);

#endif