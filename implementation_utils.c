/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:36:55 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 19:10:45 by bhocsak          ###   ########.fr       */
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

int	target_value(t_stack **a, t_stack *cur_b)
{
	t_stack	*cur_a;
	long	smallest_higher;

	cur_a = *a;
	smallest_higher = LONG_MAX;
	while (cur_a)
	{
		if (cur_b->value < cur_a->value && cur_a->value > smallest_higher)
			smallest_higher = cur_a->value;
		cur_a = cur_a->next;
	}
	if (smallest_higher == LONG_MAX)
		smallest_higher = smallest_value(a);
	return ((int)smallest_higher);
}

void	positions(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		i;

	cur_a = *a;
	cur_b = *b;
	i = 0;
	while (cur_a)
	{
		cur_a->position = i;
		cur_a = cur_a->next;
		i++;
	}
	i = 0;
	while (cur_b)
	{
		cur_b->position = i;
		cur_b = cur_b->next;
		i++;
	}
}
