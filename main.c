#include "push_swap.h"
#include <stdio.h>

static int oper = 0;

t_stacks	*butterfly(size_t len_old, t_stacks **stack_a, t_stacks *stack_b)
{
	size_t	count;
	size_t	n;

	count = 0;
	n = ideal_n(len_old);
	while (count < len_old)
	{
		if ((*stack_a)->index <= count)
		{
			do_pb(stack_a, &stack_b);
			oper++;
			do_rb(&stack_b);
			oper++;
			count++;
		}
		else if ((*stack_a)->index <= count + n)
		{
			do_pb(stack_a, &stack_b);
			oper++;
			count++;
		}
		else
		{
			do_ra(stack_a);
			oper++;
		}
	}
	return (stack_b);
}

t_stacks	*my_sorting(t_stacks **stack_b, t_stacks *stack_a, size_t len_old)
{
	size_t len;

	len = len_old;
	len_old -= 1;
	while (len_old)
	{
		if ((*stack_b)->index == len_old)
		{
			do_pa(stack_b, &stack_a);
			oper++;
			len_old--;
		}
		else
		{
			do_rrb(stack_b);
			oper++;
		}
	}
	do_pa(stack_b, &stack_a);
	oper++;
	return (stack_a);
}

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

t_stacks *final_sorting(t_stacks *stack_a, t_stacks **stack_b, size_t len_old)
{
	size_t		i;
	size_t		j;
	t_stacks	*tmp;

	i = 0;
	j = 0;
	if (len_old == 2)
	{
		do_sa(&stack_a);
		return (stack_a);
	}
	if (len_old == 3)
	{
		sorting_three(&stack_a);
		return (stack_a);
	}
	(*stack_b) = butterfly(len_old, &stack_a, *stack_b);
	stack_a = my_sorting(stack_b, stack_a, len_old);
	while(stack_a != NULL)
	{
		printf("value = %d index = %zu\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
	printf("\n");
	while((*stack_b) != NULL)
	{
		printf("value = %d index = %zu\n", (*stack_b)->value, (*stack_b)->index);
		(*stack_b) = (*stack_b)->next;
	}
	printf("\n");
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
	if (!consistently_check(stack_a, len_old))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_a = final_sorting(stack_a, &stack_b, len_old);
	printf("opers = %d\n", oper);
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
	// stack_a = free_stack(stack_a);

	// if(stack_b == NULL)
	// 	printf("b clear\n");
	// if(stack_a == NULL)
	// 	printf("a clear\n");
	// system("leaks a.out");
	return (0);
}
