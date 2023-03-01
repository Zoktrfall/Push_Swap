/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reproduce_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:52 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:53 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reproduce_pa(t_stacks **stack_a, t_stacks **stack_b)
{
	push_swap(stack_b, stack_a);
}

void	reproduce_pb(t_stacks **stack_b, t_stacks **stack_a)
{
	push_swap(stack_a, stack_b);
}
