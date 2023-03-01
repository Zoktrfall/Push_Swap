/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:57 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:58 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fatal_mistake(t_stacks **stack_a)
{
	t_stacks	*tmp;

	tmp = (*stack_a);
	tmp = tmp->next;
	if (tmp->prev->index < tmp->index
		&& tmp->index < tmp->next->index)
		return (1);
	return (0);
}

int	consistently_check(t_stacks *stack_a, size_t len_old)
{
	size_t		i;
	t_stacks	*tmp;

	i = 0;
	tmp = stack_a;
	while (i < len_old)
	{
		if (stack_a->index != i)
			return (1);
		i++;
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (0);
}
