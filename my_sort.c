#include "push_swap.h"

void	sorting_three(t_stacks **stack_a) 
{
	t_stacks	*tmp;

	tmp = *stack_a;
	if ((*stack_a)->index == 2)
	{
		do_ra(stack_a);
		if ((*stack_a)->index == 1)
			do_sa(stack_a);	
	}
	else if ((*stack_a)->next->index == 2)
	{
		do_rra(stack_a);
		if ((*stack_a)->index == 1)
			do_sa(stack_a);
	}
	else
		do_sa(stack_a);
}
