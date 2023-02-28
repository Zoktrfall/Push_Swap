#include "checker.h"

int	correct_comands(char *args)
{
	if (!ft_strcmp(args, "sa") || !ft_strcmp(args, "sb")
		|| !ft_strcmp(args, "ss") || !ft_strcmp(args, "ra")
		|| !ft_strcmp(args, "rb") || !ft_strcmp(args, "rr")
		|| !ft_strcmp(args, "rra") || !ft_strcmp(args, "rrb")
		|| !ft_strcmp(args, "rrr") || !ft_strcmp(args, "pb")
		|| !ft_strcmp(args, "pa"))
		return (0);
	return (1);
}

t_stacks	*sorting(t_stacks *stack_a, t_stacks **stack_b, char *comand)
{
	if (!ft_strcmp(comand, "sa"))
		reproduce_sa(&stack_a);
	else if (!ft_strcmp(comand, "sb"))
		reproduce_sb(stack_b);
	else if (!ft_strcmp(comand, "ss"))
		reproduce_ss(&stack_a, stack_b);
	else if (!ft_strcmp(comand, "ra"))
		reproduce_ra(&stack_a);
	else if (!ft_strcmp(comand, "rb"))
		reproduce_rb(stack_b);
	else if (!ft_strcmp(comand, "rr"))
		reproduce_rr(&stack_a, stack_b);
	else if (!ft_strcmp(comand, "rra"))
		reproduce_rra(&stack_a);
	else if (!ft_strcmp(comand, "rrb"))
		reproduce_rrb(stack_b);
	else if (!ft_strcmp(comand, "rrr"))
		reproduce_rrr(&stack_a, stack_b);
	else if (!ft_strcmp(comand, "pb"))
		reproduce_pb(stack_b, &stack_a);
	else if (!ft_strcmp(comand, "pa"))
		reproduce_pa(&stack_a, stack_b);
	return (stack_a);
}

t_stacks	*sorting_by_command(t_stacks *stack_a, t_stacks **stack_b)
{
	char	*args;

	args = NULL;
	while (1)
	{
		args = get_next_line(0, 0);
		if (args == NULL || ft_strlen(args) == 1)
			break ;
		if (correct_comands(args))
		{
			free(args);
			stack_a = free_stack(stack_a);
			print_a_standard_error();
		}
		stack_a = sorting(stack_a, stack_b, args);
		free(args);
	}
	get_next_line(0, 1);
	free(args);
	return (stack_a);
}

void	sorting_check(t_stacks **stack_a, t_stacks **stack_b, size_t len_old)
{
	if ((*stack_b) == NULL && !consistently_check(*stack_a, len_old))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
