/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:55 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:56 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stacks **stack_a)
{
	(*stack_a) = oper_sa_sb(*stack_a);
	write(1, "sa\n", 3);
}

void	do_sb(t_stacks **stack_b)
{
	(*stack_b) = oper_sa_sb(*stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stacks **stack_a, t_stacks **stack_b)
{
	(*stack_a) = oper_sa_sb(*stack_a);
	(*stack_b) = oper_sa_sb(*stack_b);
	write(1, "ss\n", 3);
}
