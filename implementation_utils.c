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

static void	all_price_tagging(int len_a, t_stack **b)
{
	t_stack	*cur_b;

	cur_b  = *b;
	while (cur_b)
	{
		cur_b->price = cur_b->position;
		if(cur_b->above_median == 0)
			cur_b->price = list_length(b) - (cur_b->position);
		if (cur_b->above_median)
			cur_b->price = cur_b->position + cur_b->target->position;
		else
			cur_b->price = cur_b->position + len_a - (cur_b->target->position);
		cur_b = cur_b->next;
	}
}

static void	setting_cheapest_hard(t_stack **a, t_stack **b, t_stack *cur_b)
{
	if (cur_b->above_median == 0 && cur_b->target->above_median == 1)
	{
		while (cur_b->position != 1)
			one_reverse_rotate(b, 'b');
		while (cur_b->target->position != 1)
			one_rotate(a, 'a');
	}
	else
	{
		while (cur_b->target->position != 1)
			one_reverse_rotate(a, 'a');
		while (cur_b->position != 1)
			one_rotate(b, 'b');
	}
}

static void	setting_cheapest_utils(t_stack **a, t_stack **b, int best_price)
{
	t_stack	*cur_b;

	cur_b = *b;
	while (cur_b->price != best_price && cur_b)
		cur_b = cur_b->next;
	if (cur_b->above_median == 0 && cur_b->target->above_median == 0)
	{
		while (cur_b->position != 1  && cur_b->target->position != 1)
			both_reverse_rotate(a, b);
		while (cur_b->position != 1 )
			one_reverse_rotate(b, 'b');
		while (cur_b->target->position != 1)
			one_reverse_rotate(a, 'a');
	}
	else if (cur_b->above_median == 1 && cur_b->target->above_median == 1)
	{
		while (cur_b->position != 1  && cur_b->target->position != 1)
			both_rotate(a, b);
		while (cur_b->position != 1)
			one_rotate(b, 'b');
		while (cur_b->target->position != 1)
			one_rotate(a, 'a');
	}
	else
		setting_cheapest_hard(a, b, cur_b);
}

void	setting_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		best_price;

	cur_a = *a;
	cur_b = *b;
	best_price = INT_MAX;
	all_price_tagging(list_length(a), b);
	while (cur_b)
	{
		if (cur_b->price < best_price)
			best_price = cur_b->price;
		cur_b = cur_b->next;
	}
	cur_b = *b;
	setting_cheapest_utils(a, b, best_price);
}
