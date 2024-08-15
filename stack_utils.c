/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:02:31 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 19:13:58 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_stack(t_stack **root) // TAKE THAT OUT
{
	t_stack	*cur;
	int		i;

	i = 1;
	cur = *root;
	while (cur)
	{
		printf("%d cur->targetv:\t%d\n", i, cur->target_value);
		cur = cur->next;
		i++;
	}
}

size_t	list_length(t_stack **root)
{
	t_stack	*cur;

	cur = *root;
	if (!root || !(*root))
		return (0);
	return (1 + list_length(&cur->next));
}

bool	is_sorted(t_stack **root, char root_name)
{
	t_stack	*cur;

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
