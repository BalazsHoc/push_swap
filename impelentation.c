/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impelentation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:11:10 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/14 12:11:13 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t  list_length(t_stack **root)
{
    t_stack *cur;
    
    cur = *root;
    if (!root || !(*root))
        return (0);
    return (1 + list_length(&cur->next));
}

bool    is_sorted(t_stack **root, char root_name)
{
    t_stack *cur;

    cur = *root;
    if (root_name == 'a')
    {
        while (cur->next)
        {
            if (cur->value > cur->next->value)
                return (0);
            cur = cur->next;
        }
    }
    else
    {
        while (cur->next)
        {
            if (cur->value < cur->next->value)
                return (0);
            cur = cur->next;
        }
    }
    return (1);
}

void    three_num_a(t_stack **root)
{
    t_stack *cur;

    cur = *root;
    if (is_sorted(root, 'a'))
        return ;
        if (cur->value > cur->next->value && cur->next->value > cur->next->next->value && cur->value > cur->next->next->value)
        {
            lets_rotate(root, 'a');
            lets_swap(root, 'a');   // 3  2  1
        }
        else if(cur->value < cur->next->value && cur->next->value > cur->next->next->value && cur->value < cur->next->next->value)
        {
            lets_swap(root, 'a');
            lets_rotate(root, 'a'); //  1  3  2
        }
        else if (cur->value > cur->next->value && cur->next->value < cur->next->next->value && cur->value > cur->next->next->value)
            lets_rotate(root, 'a'); // 3  1  2
        else if(cur->value < cur->next->value && cur->next->value > cur->next->next->value && cur->value > cur->next->next->value)
            lets_reverse_rotate(root, 'a');  //  2  3  1
        else
            lets_reverse_rotate(root, 'a'); //  2  1  3
}
