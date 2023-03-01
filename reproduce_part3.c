/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reproduce_part3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:50 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:51 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reproduce_rra(t_stacks **stack_a)
{
	(*stack_a) = oper_rra_rrb(*stack_a);
}

void	reproduce_rrb(t_stacks **stack_b)
{
	(*stack_b) = oper_rra_rrb(*stack_b);
}

void	reproduce_rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	(*stack_a) = oper_rra_rrb(*stack_a);
	(*stack_b) = oper_rra_rrb(*stack_b);
}
