#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	negative;
	long long	result;

	i = 0;
	negative = 1;
	result = 0;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
		result = 10 * result + (str[i++] - '0');
	return (result * negative);
}
