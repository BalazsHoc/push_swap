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

void	three_num_a(t_stack **root)
{
	t_stack	*cur;

	cur = *root;
	if (is_sorted(root, 'a'))
		return ;
	if (cur->value > cur->next->value && cur->next->value > cur->next->next->value && cur->value > cur->next->next->value)
	{
		one_rotate(root, 'a');
		one_swap(root, 'a');// 3 2 1
	}
	else if (cur->value < cur->next->value && cur->next->value > cur->next->next->value && cur->value < cur->next->next->value)
	{
		one_swap(root, 'a');
		one_rotate(root, 'a');// 1 3 2
	}
	else if (cur->value > cur->next->value && cur->next->value < cur->next->next->value && cur->value > cur->next->next->value)
		one_rotate(root, 'a');// 3 1 2
	else if (cur->value < cur->next->value && cur->next->value > cur->next->next->value && cur->value > cur->next->next->value)
		one_reverse_rotate(root, 'a');// 2 3 1
	else
		one_reverse_rotate(root, 'a');//2 1 3
}

void	push_swap_algorithm(t_stack **a)
{
	t_stack	*b;
	t_stack	*cur_b;

	b = NULL;
	if (list_length(a) != 3)
	{
		while (list_length(a) != 3)
		push(&b, a, 'b');
	}
	cur_b = b;
	while (cur_b)
	{
		cur_b->target_value = target_value(a, cur_b);
		cur_b = cur_b->next;
	}
	positions(a, &b);
	write_stack(&b);
}
