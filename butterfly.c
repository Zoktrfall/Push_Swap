#include "push_swap.h"

t_stacks	*butterfly(size_t len_old, t_stacks **stack_a, t_stacks *stack_b)
{
	size_t	count;
	size_t	n;

	count = 0;
	n = ideal_n(len_old);
	while (count < len_old)
	{
		if ((*stack_a)->index <= count)
		{
			do_pb(stack_a, &stack_b);
			do_rb(&stack_b);
			count++;
		}
		else if ((*stack_a)->index <= count + n)
		{
			do_pb(stack_a, &stack_b);
			count++;
		}
		else
			do_ra(stack_a);
	}
	return (stack_b);
}

void	less_b(t_stacks **stack_b, t_stacks **stack_a, size_t count)
{
	while ((*stack_b)->index != count)
		do_rb(stack_b);
	do_pa(stack_b, stack_a);
}

void	more_b(t_stacks **stack_b, t_stacks **stack_a, size_t count)
{
	while ((*stack_b)->index != count)
		do_rrb(stack_b);
	do_pa(stack_b, stack_a);
}

void	sort_stack(t_stacks **stack_b, t_stacks **stack_a, size_t len_old)
{
	t_stacks	*tmp;
	size_t		len;

	len = 0;
	tmp = (*stack_b);
	while (--len_old)
	{
		if (tmp->index == len_old)
			do_pa(stack_b, stack_a);
		else
		{
			while (tmp->index != len_old)
			{
				len++;
				tmp = tmp->next;
			}
			if (len < len_old / 2)
				less_b(stack_b, stack_a, len_old);
			else
				more_b(stack_b, stack_a, len_old);
		}
		tmp = (*stack_b);
		len = 0;
	}
	do_pa(stack_b, stack_a);
}

t_stacks	*final_sort(t_stacks *stack_a, t_stacks **stack_b, size_t len_old)
{
	if (len_old == 2)
	{
		do_sa(&stack_a);
		return (stack_a);
	}
	if (len_old == 3)
	{
		sorting_three(&stack_a);
		return (stack_a);
	}
	if (len_old >= 4 && len_old <= 12)
	{
		sorting_ten(&stack_a, stack_b, len_old);
		return (stack_a);
	}
	(*stack_b) = butterfly(len_old, &stack_a, *stack_b);
	sort_stack(stack_b, &stack_a, len_old);
	return (stack_a);
}
