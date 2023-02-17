#include "push_swap.h"

int	ispace(char space)
{
	if (space == ' ' || space == '\t' || space == '\r'
		|| space == '\v' || space == '\n' || space == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (ispace(str[i]))
		i++;
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
