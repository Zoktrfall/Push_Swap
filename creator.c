/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:08 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:09 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	add_int(int **new_mas, char **str, int **old_mas)
{
	size_t	i;
	size_t	len_new;

	i = 0;
	len_new = 0;
	while (str[i])
		i++;
	*new_mas = malloc(sizeof(int) * i);
	if (*new_mas == NULL)
		free_add_int(str, old_mas, new_mas);
	i = 0;
	while (str[i])
	{
		if (overflow_or_not(str[i]))
			overflow_error(old_mas, new_mas, str);
		(*new_mas)[len_new] = (int)ft_atoi(str[i]);
		i++;
		len_new++;
	}
	return (len_new);
}

t_stacks	*create_stack(int *old_mas, size_t len_old, t_stacks *stack_a)
{
	size_t	i;

	i = 1;
	stack_a = add_to_empty(stack_a, old_mas[0], 0);
	if (stack_a == NULL)
	{
		free(old_mas);
		exit(1);
	}
	while (i < len_old)
	{
		stack_a = add_to_end(stack_a, old_mas[i]);
		if (stack_a == NULL)
		{
			free(old_mas);
			exit(1);
		}
		i++;
	}
	free(old_mas);
	return (stack_a);
}

t_stacks	*add_to_end(t_stacks *stack, int value)
{
	t_stacks	*tmp;
	t_stacks	*tmp_start;

	tmp = (t_stacks *)malloc(sizeof(t_stacks));
	if (tmp == NULL)
		return (free_stack(stack));
	tmp->prev = NULL;
	tmp->value = value;
	tmp->next = NULL;
	tmp_start = stack;
	while (tmp_start->next != NULL)
		tmp_start = tmp_start->next;
	tmp_start->next = tmp;
	tmp->prev = tmp_start;
	return (stack);
}

t_stacks	*add_to_empty(t_stacks *stack, int value, size_t index)
{
	t_stacks	*tmp;

	tmp = (t_stacks *)malloc(sizeof(t_stacks));
	if (tmp == NULL)
		return (NULL);
	tmp->prev = NULL;
	tmp->value = value;
	tmp->index = index;
	tmp->next = NULL;
	stack = tmp;
	return (stack);
}

t_stacks	*add_to_beg(t_stacks *stack, int value, size_t index)
{
	t_stacks	*tmp;

	tmp = (t_stacks *)malloc(sizeof(t_stacks));
	if (tmp == NULL)
		free_stack(stack);
	tmp->prev = NULL;
	tmp->value = value;
	tmp->index = index;
	tmp->next = stack;
	stack->prev = tmp;
	stack = tmp;
	return (stack);
}
