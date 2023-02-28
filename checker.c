#include "checker.h"

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
	stack_a = sorting_by_command(stack_a, &stack_b);
	sorting_check(&stack_a, &stack_b, len_old);
	stack_b = free_stack(stack_b);
	stack_a = free_stack(stack_a);
	return (0);
}
