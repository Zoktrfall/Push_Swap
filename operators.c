#include "push_swap.h"

void	push_swap(t_stacks **stack_one, t_stacks **stack_two)
{
	if (*stack_one == NULL)
		return ;
	if (*stack_two == NULL)
	{
		*stack_two = add_to_empty(*stack_two, (*stack_one)->value);
		*stack_one = (*stack_one)->next;
		free((*stack_one)->prev);
		(*stack_one)->prev = NULL;
	}
	else
	{
		*stack_two = add_to_beg(*stack_two, (*stack_one)->value);
		if ((*stack_one)->next != NULL)
		{
			*stack_one = (*stack_one)->next;
			free((*stack_one)->prev);
			(*stack_one)->prev = NULL;
		}
		else
		{
			free(*stack_one);
			(*stack_one) = NULL;
		}
	}
}

t_stacks	*oper_sa_sb(t_stacks *stack)
{
	t_stacks	*tmp;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp = stack->next;
	tmp->prev = NULL;
	stack->next = stack->next->next;
	tmp->next = stack;
	stack->prev = tmp;
	stack = tmp;
	return (stack);
}

t_stacks	*oper_ra_rb(t_stacks *stack)
{
	t_stacks	*tmp;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack;
	stack->prev = tmp;
	tmp = tmp->next;
	stack = stack->next;
	tmp->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stacks	*oper_rra_rrb(t_stacks *stack)
{
	t_stacks	*tmp;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack;
	stack->prev = tmp;
	stack = tmp;
	tmp = tmp->prev;
	stack->prev = NULL;
	tmp->next = NULL;
	return (stack);
}
