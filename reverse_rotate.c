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

void	reverse_rotate(t_stack **root)
{
	t_stack	*last;

	if (!(*root) || !root)
		return ;
	last = *root;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last = (*root)->prev;
	last->next = *root;
	last->prev = NULL;
	*root = last;
	// if (root == "a")
	// 	write(1, "rra\n", 3);
	// if (root == "b")
	// 	write(1, "rrb\n", 3);
}

void	lets_reverse_rotate(t_stack **root, char rootname, bool is_both)
{
	reverse_rotate(root);
	if (rootname == 'a' && !is_both)
		write(1, "rra\n", 3);
	else if (rootname == 'b' && !is_both)
		write(1, "rrb\n", 3);
	else if (is_both)
	{
		
	}
}
