#include "push_swap.h"
#include <stdio.h>

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

size_t	add_int(int **integer_mas, char **str)
{
	size_t	i;
	size_t	len_new;

	i = 0;
	len_new = 0;
	while (str[i])
		i++;
	*integer_mas = malloc(sizeof(int) * i);
	i = 0;
	while (str[i])
	{
		(*integer_mas)[len_new] = ft_atoi(str[i]);
		i++;
		len_new++;
	}
	return (len_new);
}

int	*ft_strcat_int(int **old_mas, int *new_mas, size_t len_new, size_t len_old)
{
	size_t i;
	size_t j;
	int *new_old_mas;

	i = 0;
	j = 0;
	new_old_mas = malloc(sizeof(int) * (len_old + len_new));
	while(i < len_old)
	{
		new_old_mas[j] = (*old_mas)[i];
		i++;
		j++;
	}
	i = 0;
	while(i < len_new)
	{
		new_old_mas[j] = new_mas[i];
		i++;
		j++;
	}
	free(*old_mas);
	free(new_mas);
	return (new_old_mas);
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
			free(str);
			return (1);
		}
		len_new = add_int(&new_mas, str);
		*old_mas = ft_strcat_int(old_mas, new_mas, len_new, *len_old);
		*len_old += len_new;
		free(str);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		*old_mas;
	size_t	len_old;

	len_old = 0;
	old_mas = malloc(sizeof(int) * 1);
	if (correct_input(argv, &old_mas, &len_old))
		print_a_standard_error();
	int i = 0;
	while(i < len_old)
		printf("%d\n", old_mas[i++]);
	printf("continue\n");
	return (0);
}
