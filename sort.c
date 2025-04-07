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
    int size;
    int *arr;
    t_node *temp;
    int i;
    int j;

    size = list_size(stack);
    arr = malloc(sizeof(int) * size);
    if (!arr)
        print_error(&stack);
    temp = stack;
    i = 0;
    while (temp)
    {
        arr[i] = temp->value;
        i++;
        temp = temp->next;
    }

    // Bubble Sort (while kullanarak)
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }

    // Her düğümün sıralı dizideki indeksini belirleme
    temp = stack;
    while (temp)
    {
        i = 0;
        while (i < size)
        {
            if (temp->value == arr[i])
            {
                temp->index = i;
                break;
            }
            i++;
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

void sort_stack(t_node **stack_a, t_node **stack_b)
{
    int size;

    size = list_size(*stack_a);
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