#include "push_swap.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		++i;
	}
	return (i - 1);
}

size_t	ft_ln(size_t nb)
{
	size_t	i;
	size_t	n;

	i = 1;
	n = 4;
	while (n < nb)
	{
		n = n * 2;
		++i;
	}
	return (i - 1);
}

int	ideal_n(size_t len_old)
{
	return (ft_ln(len_old) + ft_sqrt(len_old) + 1);
}
