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

static void	price_extra(t_stack *cur_a, t_stack *cur_b, size_t l_a, size_t l_b)
{
	if (cur_a->above_median == 0 && cur_b->above_median)
		cur_b->price = cur_b->position + l_a - cur_a->position;
	else if (cur_a->above_median && cur_b->above_median == 0)
		cur_b->price = cur_a->position + l_b - cur_b->position;
	else
	{
		if (l_a >= l_b)
			cur_b->price = l_a - cur_a->position;
		else
			cur_b->price = l_b - cur_b->position;
	}
}

static void	all_price_tagging(t_stack **a, t_stack **b)
{
	t_stack	*tar_a;
	t_stack	*cur_b;

	tar_a = *a;
	cur_b = *b;
	while (cur_b)
	{
		tar_a = cur_b->target;
		if (tar_a->above_median && cur_b->above_median)
		{
			if (tar_a->position >= cur_b->position)
				cur_b->price = tar_a->position;
			else
				cur_b->price = cur_b->position;
		}
		else
			price_extra(tar_a, cur_b, list_length(a), list_length(b));
		cur_b = cur_b->next;
	}
}

static void	setting_cheapest_utils(t_stack **a, t_stack **b, int best_price)
{
	t_stack	*cur_b;

	cur_b = *b;
	while (cur_b->price != best_price && cur_b)
		cur_b = cur_b->next;
	if (cur_b->above_median)
	{
		while (cur_b != (*b) && cur_b->target != *a)
			both_reverse_rotate(a, b);
		while (cur_b->value != (*b)->value)
			one_reverse_rotate(b, 'b');
		while (cur_b->target->value != (*a)->value)
			one_reverse_rotate(a, 'a');
	}
	else
	{
		while (cur_b != (*b) && cur_b->target != *a)
			both_rotate(a, b);
		while (cur_b != (*b))
			one_rotate(b, 'b');
		while (cur_b->target != *a)
			one_rotate(a, 'a');
	}
}

void	setting_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		best_price;

	cur_a = *a;
	cur_b = *b;
	best_price = INT_MAX;
	all_price_tagging(a, b);
	while (cur_b)
	{
		if (cur_b->price < best_price)
			best_price = cur_b->price;
		cur_b = cur_b->next;
	}
	cur_b = *b;
	setting_cheapest_utils(a, b, best_price);
}
