#include "push_swap.h"

int find_min(t_node *stack)
{
    if (!stack)
        error_and_exit();  // veya uygun hata yönetimi

    int min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}

void sort_small_stack_3(t_node **stack_a)
{
    int a;
    int b;
    int c;

    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;
    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}


void sort_small_stack_4(t_node **stack_a, t_node **stack_b)
{
    int min_val;
    int size;
    int pos;
    t_node *tmp;
    
    min_val = find_min(*stack_a);
    size = list_size(*stack_a);
    pos = 0;
    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->value == min_val)
            break;
        pos++;
        tmp = tmp->next;
    }
    if (pos <= size / 2)
        while ((*stack_a)->value != min_val)
            ra(stack_a);
    else
        while ((*stack_a)->value != min_val)
            rra(stack_a);
    pb(stack_a, stack_b);
    // Artık stack_a’da 3 eleman kaldı.
    sort_small_stack_3(stack_a);
    pa(stack_b, stack_a);
}


void sort_small_stack_5(t_node **stack_a, t_node **stack_b)
{
    int min_val;
    int size;
    int pos;
    t_node *tmp;
    
    min_val = find_min(*stack_a);
    size = list_size(*stack_a);
    pos = 0;
    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->value == min_val)
            break;
        pos++;
        tmp = tmp->next;
    }
    if (pos <= size / 2)
        while ((*stack_a)->value != min_val)
            ra(stack_a);
    else
        while ((*stack_a)->value != min_val)
            rra(stack_a);
    pb(stack_a, stack_b);
    // Artık stack_a’da 4 eleman kaldı.
    sort_small_stack_4(stack_a, stack_b);
    pa(stack_b, stack_a);
}


void sort_small_stack(t_node **stack_a, t_node **stack_b)
{
    int size;

    size = list_size(*stack_a);
    if (size == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
    }
    else if (size == 3)
        sort_small_stack_3(stack_a);
    else if (size == 4)
        sort_small_stack_4(stack_a, stack_b);
    else if (size == 5)
        sort_small_stack_5(stack_a, stack_b);
}
