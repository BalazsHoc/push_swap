/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:20:50 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/17 12:20:53 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_value(t_stack **a)
{
	t_stack	*cur;
	int		smallest_value;

	cur = *a;
	smallest_value = cur->value;
	cur = cur->next;
	while (cur)
	{
		if (cur->value < smallest_value)
			smallest_value = cur->value;
		cur = cur->next;
	}
	return (smallest_value);
}

void	position_median_tag(t_stack **root)
{
	t_stack	*cur;
	size_t	i;

	cur = *root;
	if (!root || !(*root))
		return ;
	i = 1;
	while (cur)
	{
		cur->position = i;
		if (i <= (list_length(root) / 2))
			cur->above_median = true;
		else
			cur->above_median = false;
		cur = cur->next;
		i++;
	}
}
