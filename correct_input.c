#include "push_swap.h"

int	str_number(char *str)
{
	size_t	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1] != '\0'))
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str_number(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	duplicate_check(int **old_mas, size_t len_old)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len_old)
	{
		while (j < len_old)
		{
			if (j != i && (*old_mas)[i] == (*old_mas)[j])
			{
				free(*old_mas);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	correct_input(char **argv, int **old_mas, size_t *len_old)
{
	size_t		i;
	char		**str;
	int			*new_mas;
	size_t		len_new;

	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		if (check_str(str) || !str || !str[0])
		{
			free_str(str);
			return (1);
		}
		len_new = add_int(&new_mas, str, old_mas);
		free_str(str);
		*old_mas = f_cat(old_mas, new_mas, len_new, *len_old);
		*len_old += len_new;
		i++;
	}
	if (*len_old == 1 || !(*len_old))
		program_exit(old_mas);
	if (duplicate_check(old_mas, *len_old))
		return (1);
	return (0);
}
