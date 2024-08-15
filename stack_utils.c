/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:02:31 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 11:02:33 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_stack(t_stack **root) // TAKE THAT OUT
{
	t_stack	*cur;

	cur = *root;
	while (cur != NULL)
	{
		printf("cur->value: %d\n", cur->value);
		cur = cur->next;
	}
}

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
