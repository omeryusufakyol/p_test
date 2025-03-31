/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:00:27 by oakyol            #+#    #+#             */
/*   Updated: 2025/02/04 20:31:57 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

//linked list node for stack elements
typedef struct s_node {
	int	value;
	int	index;
	struct s_node	*next;
}	t_node;

// =============== UTILS ==========
void	error_and_exit(void);
t_node	*create_node(int value);
void	add_node_back(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);
int ft_atoi(const char *str, t_node **stack);


// ============== OPERATIONS ============
void	sa(t_node	**stack);
void	sb(t_node	**stack);
void	ss(t_node **a, t_node **b);
void	pa(t_node **src, t_node **dest);
void	pb(t_node **src, t_node **dest);
void	ra(t_node	**stack);
void	rb(t_node	**stack);
void	rr(t_node	**a, t_node **b);
void	rra(t_node **stack);
void	rrb(t_node	**stack);
void	rrr(t_node **a, t_node **b);

// ========= SORTING ALGORITHM (CHUNK YONTEMI) ================
int	list_size(t_node *stack);
void	assign_index(t_node *stack);
int	find_max_position(t_node *stack);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void sort_small_stack(t_node **stack_a, t_node **stack_b);
void sort_small_stack_4(t_node **stack_a, t_node **stack_b);
void sort_small_stack_5(t_node **stack_a, t_node **stack_b);
void sort_small_stack_3(t_node **stack_a);
int find_min_value(t_node *stack);

#endif