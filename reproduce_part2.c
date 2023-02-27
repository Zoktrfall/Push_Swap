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
