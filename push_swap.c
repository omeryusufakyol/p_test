/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:05:27 by oakyol            #+#    #+#             */
/*   Updated: 2025/02/04 20:38:51 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// ARGÜMAN KONTROLÜ EKLENDİ
t_node  *parse_input(int ac, char **av)
{
    t_node *stack;
    int i;
    int j;
    int value;

    stack = NULL;
    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            while (av[i][j] == ' ')
                j++;
            if (av[i][j] == '\0')
                break ;
            value = ft_atoi(&av[i][j], &stack);  // Aşağıdaki güncellenmiş ft_atoi'yi çağırıyoruz
            add_node_back(&stack, create_node(value));
            while (av[i][j] && av[i][j] != ' ')
                j++;
        }
        i++;
    }
    return (stack);
}

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    t_node  *stack_a;
    t_node  *stack_b;

    stack_b = NULL;
	if (ac < 2)
	{
		return (0);
	}
    stack_a = parse_input(ac, av);
    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }
	sort_stack(&stack_a, &stack_b);
    print_stack(stack_a);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}