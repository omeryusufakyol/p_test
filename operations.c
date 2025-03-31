/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:13:15 by oakyol            #+#    #+#             */
/*   Updated: 2025/02/04 20:48:12 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_node **src, t_node **dest)
{
	t_node	*temp;
	if (!src || !*src)
		return;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	write(1, "pa\n", 3);
}

void	pb(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!src || !*src)
		return;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	write(1, "pb\n", 3);
}

void	ra(t_node **stack)
{
	t_node	*first;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack)
{
	t_node	*first;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
	write(1, "rr\n", 3);
}

void rra(t_node **stack)
{
    t_node *prev;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *stack;
    *stack = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	t_node *prev;
	t_node *last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
	write(1, "rrr\n", 4);
}
