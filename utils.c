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
	long res;
	int i;
	int sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		print_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > MAX_INT) || (sign == -1 && -res < MIN_INT))
		{
			print_error();
			return (0);
		}
		i++;
	}
	if (str[i] != '\0')
	{
		print_error();
		return (0);
	}
	return ((int)(sign * res));
}