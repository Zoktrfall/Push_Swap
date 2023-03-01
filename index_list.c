/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:31 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:32 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_super(int *str, t_stacks *stack_a)
{
	t_stacks	*tmp;
	size_t		i;

	tmp = stack_a;
	i = 0;
	while (tmp != NULL)
	{
		str[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (str);
}

int	*str_sort(int *str, size_t len_old)
{
	size_t	i;
	size_t	swap;

	i = 0;
	while (i < len_old - 1)
	{
		if (str[i] > str[i + 1])
		{
			swap = str[i];
			str[i] = str[i + 1];
			str[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

t_stacks	*search_add(int *str, t_stacks *stack_a, size_t len_old)
{
	t_stacks	*tmp;
	size_t		i;

	i = 0;
	tmp = stack_a;
	while (stack_a != NULL)
	{
		while (i < len_old)
		{
			if (stack_a->value == str[i])
			{
				stack_a->index = i;
				break ;
			}
			i++;
		}
		i = 0;
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (stack_a);
}

t_stacks	*add_index(t_stacks *stack_a, size_t len_old)
{
	int		*str;

	str = (int *)malloc(sizeof(int) * len_old);
	if (str == NULL)
	{
		free_stack(stack_a);
		exit(1);
	}
	str = create_super(str, stack_a);
	str = str_sort(str, len_old);
	stack_a = search_add(str, stack_a, len_old);
	free(str);
	return (stack_a);
}
