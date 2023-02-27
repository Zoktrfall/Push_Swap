#include "checker.h"

void	reproduce_pa(t_stacks **stack_a, t_stacks **stack_b)
{
	push_swap(stack_b, stack_a);
}

void	reproduce_pb(t_stacks **stack_b, t_stacks **stack_a)
{
	push_swap(stack_a, stack_b);
}
