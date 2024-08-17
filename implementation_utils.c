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

static void	price_tagging_complicated(t_stack *cur_a, t_stack *cur_b)
{
	if (cur_a->above_median == 0 && cur_b->above_median)
	{
		if (list_length(a) >= list_length(b))
			cur_b->price = (list_length(a) - cur_a->position) + 1;
		else
			cur_b->price = (list_length(b) - cur_b->position) + 1;
	}
	else if (cur_a->above_median && cur_b->above_median == 0 )
	{
		if (list_length(a) >= list_length(b))
			cur_b->price = list_length(a) + (cur_b->position - cur_a->position) + 1;
		else
			cur_b->price = list_length(b) + (cur_a->position - cur_b->position) + 1;
	}
	else
		rr = true;
		if ((list_length(a) - cur_a->position) >= (list_length(b) - cur_b->position))
			cur_b->price = list_length(a) - cur_a->position;
		else
			cur_b->price = list_length(b) - cur_b->position;
}

static void	all_price_tagging(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *a;
	cur_b = *b;
	while (cur_b)
	{
		if (cur_a->above_median && cur_b->above_median)
		{
			if (cur_a->position >= cur_b->position)
				cur_b->price = cur_a->position + 1;
			else
				cur_b->price = cur_b->position + 1;
		}
		else
			price_tagging_complicated(cur_a, cur_b);
		cur_b = cur_b->next;
	}
}

static void	setting_cheapest_rr_utils(t_stack **a, t_stack **b, int moves)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *a;
	cur_b = *b;
	if (cur_b->rr)
	{
		while (cur_a->position && cur_b->position)
		{
			both_reverse_rotate(a, b);
			cur_a->position--;
			cur_b->position--;
		}
		while (cur_a->position)
		{
			one_reverse_rotate(a);
			cur_a->position--;
		}
		while (cur_b->position)
		{
			one_reverse_rotate(a);
			cur_b->position--;
		}
	}
	setting_cheapest_r_utils;
}
static void	setting_cheapest_r_utils(t_stack **a, t_stack **b, int moves)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *a;
	cur_b = *b;
	if (!cur_b->rr)
	{
		while (cur_a->position && cur_b->position)
		{
			both_rotate(a, b);
			cur_a->position--;
			cur_b->position--;
		}
		while (cur_a->position)
		{
			one_rotate(a);
			cur_a->position--;
		}
		while (cur_b->position)
		{
			one_rotate(b);
			cur_b->position--;
		}
	}
}

void	setting_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		moves;

	cur_a = *a;
	cur_b = *b;
	moves = INT_MAX;
	all_price_tagging(a, b);
	while (cur_b)
	{
		if (cur_b->price > moves)
			moves = cur_b->price;
		cur_b = cur_b->next;
	}
	cur_b = *b;
	while (cur_b)
	{
		if (cur_b->price = moves)
			break ;
		cur_b = cur_b->next;
	}
	setting_cheapest_rr_utils(a, b, moves);
	push(a, b, 'b');
}
