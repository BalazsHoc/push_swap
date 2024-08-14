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

void    three_num(t_stack **root, char root_name)
{
    if (is_sorted(root, root_name))
        return ;
    
}