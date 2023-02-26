#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	a;
	size_t	len;

	a = 0;
	len = 0;
	while (str[a] != '\0' && str[a] == '0')
		a++;
	len = a;
	while (str[len] != '\0')
		len++;
	return (len - a);
}
