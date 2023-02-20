#include "push_swap.h"
#include <stdio.h>

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
	if (correct_input(argv, &old_mas, &len_old))
		print_a_standard_error();
	stack_b = NULL;
	stack_a = NULL;
	stack_a = create_stack(old_mas, len_old, stack_a);
	stack_a = add_index(stack_a, len_old);
	// while(stack_a != NULL)
	// {
	// 	printf("%d %zu\n", stack_a->value, stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// printf("\n");	
	system("leaks a.out");
	return (0);
}
