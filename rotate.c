/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:47:21 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:20:51 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **root)
{
	t_stack	*last;

	if (!(*root) || !root)
		return ;
	last = *root;
	while (last->next)
		last = last->next;
	*root = (*root)->next;
	(*root)->prev->prev = last;
	last->next = (*root)->prev;
	last->next->prev = last;
	last->next->next = NULL;
	(*root)->prev = NULL;
}

void	one_rotate(t_stack **root, char rootname)
{
	rotate(root);
	if (rootname == 'a')
		write(1, "ra\n", 3);
	else if (rootname == 'b')
		write(1, "rb\n", 3);
}

void	both_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
