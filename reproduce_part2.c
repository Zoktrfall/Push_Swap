/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reproduce_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:48 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:49 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reproduce_ra(t_stacks **stack_a)
{
	(*stack_a) = oper_ra_rb(*stack_a);
}

void	reproduce_rb(t_stacks **stack_b)
{
	(*stack_b) = oper_ra_rb(*stack_b);
}

void	reproduce_rr(t_stacks **stack_a, t_stacks **stack_b)
{
	(*stack_a) = oper_ra_rb(*stack_a);
	(*stack_b) = oper_ra_rb(*stack_b);
}
