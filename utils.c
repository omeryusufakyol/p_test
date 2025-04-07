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

void print_error(t_node **stack)
{
    free_stack(stack);
    write(2, "Error\n", 6);
    exit(1);
}

int ft_atoi(const char *str, t_node **stack)
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
    if (str[i] != '\0')
        print_error(stack);
    
    if ((result * sign) > MAX_INT || (result * sign) < MIN_INT)
        print_error(stack);
    return ((int)(result * sign));
}
