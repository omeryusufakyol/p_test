#include "push_swap.h"

void	check_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
                print_error(&stack);
			checker = checker->next;
		}
		current = current->next;
	}
}