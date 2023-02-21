#include "push_swap.h"
#include <stdio.h>

t_stacks	*butterfly(size_t len_old, t_stacks **stack_a, t_stacks *stack_b, int *counts)
{
	size_t	count;
	size_t	n;

	count = 0;
	n = 1;
	while (count < len_old)
	{
		if ((*stack_a)->index <= count)
		{
			do_pb(stack_a, &stack_b);
			(*counts)++;
			do_rb(&stack_b);
			(*counts)++;
			count++;
		}
		else if ((*stack_a)->index <= count + n)
		{
			do_pb(stack_a, &stack_b);
			(*counts)++;
			count++;
		}
		else
		{
			do_ra(stack_a);
			(*counts)++;
		}
	}
	return (stack_b);
}

t_stacks	*my_sorting(t_stacks **stack_b, t_stacks *stack_a, size_t len_old, int *counts)
{
	len_old -= 1;
	while (len_old)
	{
		if ((*stack_b)->index == len_old)
		{
			do_pa(stack_b, &stack_a);
			(*counts)++;
			len_old--;
		}
		else
		{
			do_rrb(stack_b);
			(*counts)++;
		}
	}
	do_pa(stack_b, &stack_a);
	(*counts)++;
	return (stack_a);
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


	static int counts = 0;
	stack_b = butterfly(len_old, &stack_a, stack_b, &counts);
	stack_a = my_sorting(&stack_b, stack_a, len_old, &counts);
	printf("elemenst = %zu\n", len_old);
	printf("operetions = %d\n", counts);
	while(stack_a != NULL)
	{
		printf("value = %d index = %zu\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
	printf("\n");
	while(stack_b != NULL)
	{
		printf("value = %d index = %zu\n", stack_b->value, stack_b->index);
		stack_b = stack_b->next;
	}
	printf("\n");	


	// system("leaks a.out");
	return (0);
}
