#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	s;

	s = 0;
	while (s1[s] != '\n' && s2[s])
	{
		if (s1[s] > s2[s])
			return (1);
		if (s1[s] < s2[s])
			return (1);
		++s;
	}
	if (s1[s] == '\n' && !s2[s])
		return (0);
	return (1);
}
