#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stacks {
	struct s_stacks		*prev;
	size_t				index;
	int					value;
	struct s_stacks		*next;
}	t_stacks;

//Utilits
char		**ft_split(const char *s, char c);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoi(const char *str);
size_t		ft_strlen(char *str);
int			*ft_strcat(int **old_mas, int *new_mas, \
						size_t len_new, size_t len_old);

//Comand Sorting
int			correct_comands(char *args);
t_stacks	*sorting(t_stacks *stack_a, t_stacks **stack_b, char *comand);
t_stacks	*sorting_by_command(t_stacks *stack_a, t_stacks **stack_b);
void		sorting_check(t_stacks **stack_a, t_stacks **stack_b, \
							size_t len_old);

//Reproduce
void		reproduce_sa(t_stacks **stack_a);
void		reproduce_sb(t_stacks **stack_b);
void		reproduce_sa_sb(t_stacks **stack_a, t_stacks **stack_b);
void		reproduce_ra(t_stacks **stack_a);
void		reproduce_rb(t_stacks **stack_b);
void		reproduce_rr(t_stacks **stack_a, t_stacks **stack_b);
void		reproduce_rra(t_stacks **stack_a);
void		reproduce_rrb(t_stacks **stack_b);
void		reproduce_rrr(t_stacks **stack_a, t_stacks **stack_b);
void		reproduce_pa(t_stacks **stack_a, t_stacks **stack_b);
void		reproduce_pb(t_stacks **stack_b, t_stacks **stack_a);

//Correct Input
int			fatal_mistake(t_stacks **stack_a);
int			consistently_check(t_stacks *stack_a, size_t len_old);
int			check_str(char **str);
int			correct_input(int arc, char **argv, int **old_mas, size_t *len_old);
int			str_number(char *str);
int			duplicate_check(int **old_mas, size_t len_old);
int			overflow_or_not(char *str);

//Creator
size_t		add_int(int **new_mas, char **str, int **old_mas);
t_stacks	*create_stack(int *old_mas, size_t len_old, t_stacks *stack_a);
t_stacks	*add_to_beg(t_stacks *stack, int value, size_t index);
t_stacks	*add_to_end(t_stacks *stack, int value);
t_stacks	*add_to_empty(t_stacks *stack, int value, size_t index);

//Operators
void		push_swap(t_stacks **stack1, t_stacks **stack2);
t_stacks	*oper_sa_sb(t_stacks *stack);
t_stacks	*oper_ra_rb(t_stacks *stack);
t_stacks	*oper_rra_rrb(t_stacks *stack);

//Super_mas
int			*create_super(int *str, t_stacks *stack_a);
int			*str_sort(int *str, size_t len_old);
t_stacks	*add_index(t_stacks *stack_a, size_t len_old);
t_stacks	*search_add(int *str, t_stacks *stack_a, size_t len_old);

//Get_Next_Line
char		*get_next_line(int fd, int check);
char		*replace_str(int fd, char *ptr, char *str);
char		*new_str(char *str);
char		*new_ptr(char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_strjoin_exlusive(char *str, char *ptr);
char		*adds(char *ptr);
int			characters_str(char *str);
int			characters_ptr(char *str);

//Errors and Exits
void		emergency_exit(t_stacks **stack);
void		print_a_standard_error(void);
void		program_exit(int **old_mas);
void		overflow_error(int **old_mas, int **new_mas, char **str);

//Frees
void		free_element(t_stacks **stack_one);
void		free_add_int(char **str, int **old_mas, int **new_mas);
void		free_old_new(int **old_mas, int *new_mas);
void		free_str(char **str);
t_stacks	*free_stack(t_stacks *stack);

#endif