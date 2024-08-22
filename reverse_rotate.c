/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:05:09 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:17:52 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **root)
{
	t_stack	*last;

	last = *root;
	if (!(*root) || !root)
		return ;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *root;
	last->prev = NULL;
	last->next->prev = last;
	*root = last;
	(*root)->position = 0;
}

void	one_reverse_rotate(t_stack **root, char rootname)
{
	reverse_rotate(root);
	if (rootname == 'a')
		write(1, "rra\n", 4);
	else if (rootname == 'b')
		write(1, "rrb\n", 4);
}

void	both_reverse_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
