/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:36:42 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 19:07:56 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_num(t_stack **root)
{
	t_stack	*cur;
	int		highest;

	highest = 0;
	cur = (*root);
	while (cur)
	{
		if (cur->value > highest)
			highest = cur->value;
		cur = cur->next;
	}
	return (highest);
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

void	three_num_a(t_stack **root)
{
	t_stack	*cur;
	int		highest;

	cur = (*root)->next;
	highest = highest_num(root);
	if (is_sorted(root, 'a'))
		return ;
	if (cur->value == highest)
	{
		one_reverse_rotate(root, 'a');
		if (!is_sorted(root, 'a'))
			one_swap(root, 'a');
		return ;
	}
	else if (cur->next->value == highest)
	{
		one_swap(root, 'a');
		if (!is_sorted(root, 'a'))
			one_swap(root, 'a');
		return ;
	}
	one_rotate(root, 'a');
	if (!is_sorted(root, 'a'))
		one_swap(root, 'a');
}

void	push_swap_algorithm(t_stack **a, t_stack **b)
{
	t_stack	*cur_b;

	cur_b = *b;
	if (list_length(a) != 3)
	{
		while (list_length(a) != 3)
			push(b, a, 'b');
	}
	cur_b = *b;
	while (cur_b)
	{
		while (cur_b)
		{
			cur_b->target_value = target_value(a, cur_b);
			cur_b = cur_b->next;
		}
		position_median_tag(a);
		position_median_tag(b);
		setting_cheapest(a, b);
		push(a, b, 'a');
		cur_b = *b;
	}
	write_stack(b);
}
