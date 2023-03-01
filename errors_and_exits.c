/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_exits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:10 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:11 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a_standard_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	program_exit(int **old_mas)
{
	free(*old_mas);
	exit(0);
}

void	emergency_exit(t_stacks **stack)
{
	free_stack(*stack);
	exit(1);
}

void	overflow_error(int **old_mas, int **new_mas, char **str)
{
	free_str(str);
	free(*old_mas);
	free(*new_mas);
	print_a_standard_error();
}
