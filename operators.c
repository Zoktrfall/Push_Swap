#include "push_swap.h"

t_stacks	*oper_sa(t_stacks *head)
{
	t_stacks	*tmp;

	if (head == NULL || head->next == NULL)
		return (head);
	tmp = head->next;
	tmp->prev = NULL;
	head->next = head->next->next;
	tmp->next = head;
	head->prev = tmp;
	head = tmp;
	return (head);
}

t_stacks	*oper_ra(t_stacks *head)
{
	t_stacks	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = head;
	head->prev = tmp;
	tmp = tmp->next;
	head = head->next;
	tmp->next = NULL;
	head->prev = NULL;
	return (head);
}

t_stacks	*oper_rra(t_stacks *head)
{
	t_stacks	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = head;
	head->prev = tmp;
	head = tmp;
	tmp = tmp->prev;
	head->prev = NULL;
	tmp->next = NULL;
	return (head);
}
