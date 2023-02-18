#include "push_swap.h"

size_t	add_int(int **new_mas, char **str, int **old_mas)
{
	size_t	i;
	size_t	len_new;

	i = 0;
	len_new = 0;
	while (str[i])
		i++;
	*new_mas = malloc(sizeof(int) * i);
	if (*new_mas == NULL)
		free_add_int(str, old_mas, new_mas);
	i = 0;
	while (str[i])
	{
		(*new_mas)[len_new] = ft_atoi(str[i]);
		i++;
		len_new++;
	}
	return (len_new);
}

t_stacks	*create_stack(int *old_mas, size_t len_old, t_stacks *stack_a)
{
	size_t	i;

	i = 1;
	stack_a = add_to_empty(stack_a, old_mas[0]);
	if (stack_a == NULL)
	{
		free(old_mas);
		exit(1);
	}
	while (i < len_old)
	{
		stack_a = add_to_end(stack_a, old_mas[i]);
		if (stack_a == NULL)
		{
			free(old_mas);
			exit(1);
		}
		i++;
	}
	free(old_mas);
	return (stack_a);
}

t_stacks	*add_to_end(t_stacks *stack_a, int value)
{
	t_stacks	*tmp;
	t_stacks	*tmp_start;

	tmp = (t_stacks *)malloc(sizeof(t_stacks));
	if (tmp == NULL)
		return (free_stack_a(stack_a));
	tmp->prev = NULL;
	tmp->value = value;
	tmp->next = NULL;
	tmp_start = stack_a;
	while (tmp_start->next != NULL)
		tmp_start = tmp_start->next;
	tmp_start->next = tmp;
	tmp->prev = tmp_start;
	return (stack_a);
}

t_stacks	*add_to_empty(t_stacks *stack_a, int value)
{
	t_stacks	*tmp;

	tmp = (t_stacks *)malloc(sizeof(t_stacks));
	if (tmp == NULL)
		return (NULL);
	tmp->prev = NULL;
	tmp->value = value;
	tmp->next = NULL;
	stack_a = tmp;
	return (stack_a);
}

t_stacks	*add_to_beg(t_stacks *stack_a, int value)
{
	t_stacks	*tmp;

	tmp = (t_stacks *)malloc(sizeof(t_stacks));
	tmp->prev = NULL;
	tmp->value = value;
	tmp->next = stack_a;
	stack_a->prev = tmp;
	stack_a = tmp;
	return (stack_a);
}
