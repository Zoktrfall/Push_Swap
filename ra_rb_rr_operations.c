/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:45 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:46 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stacks **stack_a)
{
	(*stack_a) = oper_ra_rb(*stack_a);
	write(1, "ra\n", 3);
}

void	do_rb(t_stacks **stack_b)
{
	(*stack_b) = oper_ra_rb(*stack_b);
	write(1, "rb\n", 3);
}

void	do_rr(t_stacks **stack_a, t_stacks **stack_b)
{
	(*stack_a) = oper_ra_rb(*stack_a);
	(*stack_b) = oper_ra_rb(*stack_b);
	write(1, "rr\n", 3);
}
