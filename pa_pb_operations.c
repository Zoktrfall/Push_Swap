/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:39 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:40 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stacks **stack_b, t_stacks **stack_a)
{
	push_swap(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	do_pb(t_stacks **stack_a, t_stacks **stack_b)
{
	push_swap(stack_a, stack_b);
	write(1, "pb\n", 3);
}
