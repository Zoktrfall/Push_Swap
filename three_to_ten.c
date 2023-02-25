#include "push_swap.h"

size_t	max(t_stacks **stack)
{
	t_stacks	*tmp;
	size_t		max;
	int			i;

	tmp = *stack;
	i = 2;
	max = tmp->index;
	while (i)
	{
		if (max < tmp->next->index)
			max = tmp->next->index;
		tmp = tmp->next;
		i--;
	}
	return (max);
}

void	sorting_three(t_stacks **stack_a)
{
	size_t		max_index;

	max_index = max(stack_a);
	if ((*stack_a)->index == max_index)
	{
		do_ra(stack_a);
		if ((*stack_a)->index == max_index - 1)
			do_sa(stack_a);
	}
	else if ((*stack_a)->next->index == max_index)
	{
		do_rra(stack_a);
		if ((*stack_a)->index == max_index - 1)
			do_sa(stack_a);
	}
	else
		do_sa(stack_a);
}

void	less(t_stacks **stack_a, t_stacks **stack_b, size_t count)
{
	while ((*stack_a)->index != count)
		do_ra(stack_a);
	do_pb(stack_a, stack_b);
}

void	more(t_stacks **stack_a, t_stacks **stack_b, size_t count)
{
	while ((*stack_a)->index != count)
		do_rra(stack_a);
	do_pb(stack_a, stack_b);
}

void	sorting_ten(t_stacks **stack_a, t_stacks **stack_b, size_t len_old)
{
	size_t		count;
	size_t		len_check;
	t_stacks	*tmp;

	count = 0;
	len_check = 0;
	tmp = (*stack_a);
	while (count < len_old - 3)
	{
		while (tmp->index != count)
		{
			len_check++;
			tmp = tmp->next;
		}
		if (len_check < len_old / 2)
			less(stack_a, stack_b, count);
		else
			more(stack_a, stack_b, count);
		tmp = (*stack_a);
		len_check = 0;
		count++;
	}
	sorting_three(stack_a);
	while ((*stack_b) != NULL)
		do_pa(stack_b, stack_a);
}
