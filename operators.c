#include "push_swap.h"

void	push_swap(t_stacks **stack1, t_stacks **stack2)
{
	if (*stack1 == NULL)
		return ;
	if (*stack2 == NULL)
	{
		*stack2 = add_to_empty(*stack2, (*stack1)->value, (*stack1)->index);
		if (*stack2 == NULL)
			emergency_exit(stack1);
		*stack1 = (*stack1)->next;
		free((*stack1)->prev);
		(*stack1)->prev = NULL;
	}
	else
	{
		*stack2 = add_to_beg(*stack2, (*stack1)->value, (*stack1)->index);
		if (*stack2 == NULL)
			emergency_exit(stack1);
		if ((*stack1)->next != NULL)
			free_element(stack1);
		else
		{
			free(*stack1);
			(*stack1) = NULL;
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
	if (tmp->next->next != NULL)
	{
		tmp = tmp->next->next;
		tmp->prev = stack->next;
	}
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
