#include "push_swap.h"

void	do_rra(t_stacks **stack_a)
{
	(*stack_a) = oper_rra_rrb(*stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stacks **stack_b)
{
	(*stack_b) = oper_rra_rrb(*stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	(*stack_a) = oper_rra_rrb(*stack_a);
	(*stack_b) = oper_rra_rrb(*stack_b);
	write(1, "rrr\n", 4);
}
