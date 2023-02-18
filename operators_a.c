#include "push_swap.h"

t_stacks	*oper_sa(t_stacks *stack_a)
{
	t_stacks	*tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return (stack_a);
	tmp = stack_a->next;
	tmp->prev = NULL;
	stack_a->next = stack_a->next->next;
	tmp->next = stack_a;
	stack_a->prev = tmp;
	stack_a = tmp;
	return (stack_a);
}

t_stacks	*oper_ra(t_stacks *stack_a)
{
	t_stacks	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack_a;
	stack_a->prev = tmp;
	tmp = tmp->next;
	stack_a = stack_a->next;
	tmp->next = NULL;
	stack_a->prev = NULL;
	return (stack_a);
}

t_stacks	*oper_rra(t_stacks *stack_a)
{
	t_stacks	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack_a;
	stack_a->prev = tmp;
	stack_a = tmp;
	tmp = tmp->prev;
	stack_a->prev = NULL;
	tmp->next = NULL;
	return (stack_a);
}

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
			free(*stack_one);
	}
}
