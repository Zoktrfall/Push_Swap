#include "push_swap.h"

void	free_old_new(int **old_mas, int *new_mas)
{
	if (*old_mas != NULL)
	{
		free(*old_mas);
		*old_mas = NULL;
	}
	if (new_mas)
	{
		free(new_mas);
		new_mas = NULL;
	}
	exit(1);
}

void	free_add_int(char **str, int **old_mas, int **new_mas)
{
	free_str(str);
	if (*old_mas != NULL)
	{
		free(*old_mas);
		*old_mas = NULL;
	}
	if (*new_mas != NULL)
	{
		free(*new_mas);
		*new_mas = NULL;
	}
	exit(1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

t_stacks	*free_stack_a(t_stacks *stack_a)
{
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		free(stack_a->prev);
		stack_a->prev = NULL;
	}
	free(stack_a);
	return (NULL);
}
