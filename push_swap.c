#include "push_swap.h"

int	consistently_check(t_stacks *stack_a, size_t len_old)
{
	size_t		i;
	t_stacks	*tmp;

	i = 0;
	tmp = stack_a;
	while (i < len_old)
	{
		if (stack_a->index != i)
			return (1);
		i++;
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (0);
}

int	main(int argc, char *argv[])
{
	int			*old_mas;
	size_t		len_old;
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	len_old = 0;
	old_mas = malloc(sizeof(int) * 1);
	if (old_mas == NULL)
		return (1);
	if (correct_input(argc, argv, &old_mas, &len_old))
		print_a_standard_error();
	stack_b = NULL;
	stack_a = NULL;
	stack_a = create_stack(old_mas, len_old, stack_a);
	stack_a = add_index(stack_a, len_old);
	if (!consistently_check(stack_a, len_old))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_a = final_sort(stack_a, &stack_b, len_old);
	stack_a = free_stack(stack_a);
	return (0);
}
