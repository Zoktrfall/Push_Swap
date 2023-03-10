/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:12 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:13 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_old_new(int **old_mas, int *new_mas)
{
	if (*old_mas != NULL)
	{
		free(*old_mas);
		*old_mas = NULL;
	}
	if (new_mas)
	{
		free(new_mas);
		new_mas = NULL;
	}
	exit(1);
}

void	free_add_int(char **str, int **old_mas, int **new_mas)
{
	free_str(str);
	if (*old_mas != NULL)
	{
		free(*old_mas);
		*old_mas = NULL;
	}
	if (*new_mas != NULL)
	{
		free(*new_mas);
		*new_mas = NULL;
	}
	exit(1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

t_stacks	*free_stack(t_stacks *stack)
{
	t_stacks	*tmp;

	if (stack == NULL)
		return (NULL);
	tmp = stack;
	while (tmp != NULL)
	{
		stack = stack->next;
		free(tmp);
		tmp = stack;
	}
	free(tmp);
	return (NULL);
}

void	free_element(t_stacks **stack_one)
{
	if ((*stack_one) == NULL)
		return ;
	*stack_one = (*stack_one)->next;
	free((*stack_one)->prev);
	(*stack_one)->prev = NULL;
}
