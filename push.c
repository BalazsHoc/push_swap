/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:30:42 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:19:43 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
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

	
	// if (dest == "a")
	// 	write(1, "pa\n", 3);
	// if (dest == "b")
	// 	write(1, "pb\n", 3);
}
