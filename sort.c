/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakyol <oakyol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:30:47 by oakyol            #+#    #+#             */
/*   Updated: 2025/02/04 20:32:28 by oakyol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	list_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void assign_index(t_node *stack)
{
    int size = list_size(stack);
    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        error_and_exit();

    t_node *temp = stack;
    int i = 0;
    while (temp)
    {
        arr[i++] = temp->value;
        temp = temp->next;
    }
    // Basit bubble sort ile dizi sıralanıyor
    for (i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    // Her node için, sıralı dizideki konumunu bulup index olarak atıyoruz.
    temp = stack;
    while (temp)
    {
        for (i = 0; i < size; i++)
        {
            if (temp->value == arr[i])
            {
                temp->index = i;
                break;
            }
        }
        temp = temp->next;
    }
    free(arr);
}

int find_max_position(t_node *stack)
{
    int max = -1;
    int pos = 0;
    int max_pos = 0;
    t_node *temp = stack;
    while (temp)
    {
        if (temp->index > max)
        {
            max = temp->index;
            max_pos = pos;
        }
        pos++;
        temp = temp->next;
    }
    return max_pos;
}

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
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

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
    int min_val = find_min(*stack_a);
    int size = list_size(*stack_a);
    int pos = 0;
    t_node *tmp = *stack_a;
    
    while (tmp)
    {
        if (tmp->value == min_val)
            break;
        pos++;
        tmp = tmp->next;
    }
    
    if (pos <= size / 2)
    {
        while ((*stack_a)->value != min_val)
            ra(stack_a);
    }
    else
    {
        while ((*stack_a)->value != min_val)
            rra(stack_a);
    }
    
    pb(stack_a, stack_b);
    // Artık stack_a’da 3 eleman kaldı.
    sort_small_stack_3(stack_a);
    pa(stack_b, stack_a);
}


void sort_small_stack_5(t_node **stack_a, t_node **stack_b)
{
    int min_val = find_min(*stack_a);
    int size = list_size(*stack_a);
    int pos = 0;
    t_node *tmp = *stack_a;
    
    while (tmp)
    {
        if (tmp->value == min_val)
            break;
        pos++;
        tmp = tmp->next;
    }
    
    if (pos <= size / 2)
    {
        while ((*stack_a)->value != min_val)
            ra(stack_a);
    }
    else
    {
        while ((*stack_a)->value != min_val)
            rra(stack_a);
    }
    
    pb(stack_a, stack_b);
    // Artık stack_a’da 4 eleman kaldı.
    sort_small_stack_4(stack_a, stack_b);
    pa(stack_b, stack_a);
}


void sort_small_stack(t_node **stack_a, t_node **stack_b)
{
    int size = list_size(*stack_a);

    if (size == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
    }
    else if (size == 3)
    {
        sort_small_stack_3(stack_a);
    }
    else if (size == 4)
    {
        sort_small_stack_4(stack_a, stack_b);
    }
    else if (size == 5)
    {
        sort_small_stack_5(stack_a, stack_b);
    }
}



void sort_stack(t_node **stack_a, t_node **stack_b)
{
    int size = list_size(*stack_a);

    if (size <= 5)
    {
        // 5 veya daha az eleman için küçük sıralama fonksiyonunu kullan
        sort_small_stack(stack_a, stack_b);
        return ;
    }

    assign_index(*stack_a);
    // 100 sayı için genellikle 5 veya 6 chunk iyi sonuç verir. Burada sabit chunk boyutunu 20 olarak belirledik.
    int chunk_size = 20;
    int current_chunk = chunk_size;

    // Stack A’dan B’ye elemanları aktarırken:
    while (*stack_a)
    {
        if ((*stack_a)->index < current_chunk)
        {
            pb(stack_a, stack_b);
            // Eğer taşınan elemanın indexi, chunk’ın alt yarısındaysa, stack B’de aşağı rotasyon yaparak,
            // daha sonra daha hızlı doğru pozisyona getirebilmek için.
            if (*stack_b && (*stack_b)->index < current_chunk - (chunk_size / 2))
                rb(stack_b);
        }
        else
        {
            ra(stack_a);
        }
        // Stack B’deki eleman sayısı, mevcut chunk boyutuna eşit olunca sonraki chunk'a geçiyoruz.
        if (list_size(*stack_b) == current_chunk && current_chunk < size)
            current_chunk += chunk_size;
    }
    // Şimdi, stack B’deki elemanları en büyük indeksten başlayarak stack A’ya geri taşıyoruz.
    while (*stack_b)
    {
        int pos = find_max_position(*stack_b);
        int size_b = list_size(*stack_b);
        if (pos <= size_b / 2)
        {
            while (pos-- > 0)
                rb(stack_b);
        }
        else
        {
            pos = size_b - pos;
            while (pos-- > 0)
                rrb(stack_b);
        }
        pa(stack_b, stack_a);
    }
}