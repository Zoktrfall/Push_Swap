/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:41 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:42 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			*old_mas;
	size_t		len_old;
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	len_old = 0;
	old_mas = malloc(sizeof(int) * 1);
	if (old_mas == NULL)
		return (1);
	if (correct_input(argc, argv, &old_mas, &len_old))
		print_a_standard_error();
	stack_b = NULL;
	stack_a = NULL;
	stack_a = create_stack(old_mas, len_old, stack_a);
	stack_a = add_index(stack_a, len_old);
	if (!consistently_check(stack_a, len_old))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_a = final_sort(stack_a, &stack_b, len_old);
	stack_a = free_stack(stack_a);
	return (0);
}
