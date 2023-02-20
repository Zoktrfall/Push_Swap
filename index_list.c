#include "push_swap.h"

t_super	*create_super(t_super *str, t_stacks *stack_a)
{
	t_stacks	*tmp;
	size_t		i;

	tmp = stack_a;
	i = 0;
	while (tmp != NULL)
	{
		str[i].data = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (str);
}

t_super	*str_sort(t_super *str, size_t len_old)
{
	size_t	i;
	size_t	swap;

	i = 0;
	while (i < len_old - 1)
	{
		if (str[i].data > str[i + 1].data)
		{
			swap = str[i].data;
			str[i].data = str[i + 1].data;
			str[i + 1].data = swap;
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

t_super	*create_index(t_super *str, size_t len_old)
{
	size_t	i;

	i = 0;
	while (i < len_old)
	{
		str[i].index = i;
		i++;
	}
	return (str);
}

t_stacks	*search_add(t_super *str, t_stacks *stack_a, size_t len_old)
{
	t_stacks	*tmp;
	size_t		i;

	i = 0;
	tmp = stack_a;
	while (stack_a != NULL)
	{
		while (i < len_old)
		{
			if (stack_a->value == str[i].data)
			{
				stack_a->index = str[i].index;
				break ;
			}
			i++;
		}
		i = 0;
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (stack_a);
}

t_stacks	*add_index(t_stacks *stack_a, size_t len_old)
{
	t_super		*str;

	str = (t_super *)malloc(sizeof(t_super) * len_old);
	if (str == NULL)
	{
		free_stack(stack_a);
		exit(1);
	}
	str = create_super(str, stack_a);
	str = str_sort(str, len_old);
	str = create_index(str, len_old);
	stack_a = search_add(str, stack_a, len_old);
	free(str);
	return (stack_a);
}
