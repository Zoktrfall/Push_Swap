/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reproduce_part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:47 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:48 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reproduce_sa(t_stacks **stack_a)
{
	(*stack_a) = oper_sa_sb(*stack_a);
}

void	reproduce_sb(t_stacks **stack_b)
{
	(*stack_b) = oper_sa_sb(*stack_b);
}

void	reproduce_ss(t_stacks **stack_a, t_stacks **stack_b)
{
	(*stack_a) = oper_sa_sb(*stack_a);
	(*stack_b) = oper_sa_sb(*stack_b);
}
