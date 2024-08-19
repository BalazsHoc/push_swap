/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:30:42 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 19:17:18 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	one_push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (!(*src))
		return ;
	push_node = *src;
	push_node->prev = NULL;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!(*dest))
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = (*dest);
		*dest = push_node;
		push_node->next->prev = push_node;
	}
	push_node->prev = NULL;
}

void	push(t_stack **dest, t_stack **src, char destname)
{
	one_push(dest, src);
	if (destname == 'a')
		write(1, "pa\n", 3);
	if (destname == 'b')
		write(1, "pb\n", 3);
	position_median_tag(dest);
	position_median_tag(src);
}
