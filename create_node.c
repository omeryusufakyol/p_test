#include "push_swap.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_node	*create_node(int value)
{
	t_node	*new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_and_exit();
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
