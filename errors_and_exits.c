#include "push_swap.h"

void	print_a_standard_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	program_exit(int **old_mas)
{
	free(*old_mas);
	exit(0);
}
