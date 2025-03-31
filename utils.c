/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:08:28 by oakyol            #+#    #+#             */
/*   Updated: 2025/02/04 20:13:13 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!stack || !new_node)
		return;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    long result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result *= sign;
    if (result > MAX_INT || result < MIN_INT)
        print_error();
    return (int)result;
}