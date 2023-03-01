/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:05 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:06 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflow_or_not(char *str)
{
	int			minus;
	int			i;
	long long	oper;

	oper = 0;
	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		oper = oper * 10 + str[i] - '0';
		i++;
	}
	oper *= minus;
	if (oper > +2147483647 || oper < -2147483648)
		return (1);
	return (0);
}

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
	if (ft_strlen(str) > 11)
		return (1);
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

int	correct_input(int arc, char **argv, int **old_mas, size_t *len_old)
{
	size_t		i;
	char		**str;
	int			*new_mas;
	size_t		len_new;

	i = 0;
	while (++i < (size_t)arc)
	{
		str = ft_split(argv[i], ' ');
		if (check_str(str) || !str || !str[0])
		{
			free_str(str);
			free(*old_mas);
			return (1);
		}
		len_new = add_int(&new_mas, str, old_mas);
		free_str(str);
		*old_mas = ft_strcat(old_mas, new_mas, len_new, *len_old);
		*len_old += len_new;
	}
	if (*len_old == 1 || !(*len_old))
		program_exit(old_mas);
	if (duplicate_check(old_mas, *len_old))
		return (1);
	return (0);
}
