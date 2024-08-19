/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:58:42 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 19:16:17 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **root)
{
	t_stack	*cur;

	cur = *root;
	if (!root || !(*root))
		return ;
	*root = (*root)->next;
	cur->next = (*root)->next;
	(*root)->next = cur;
	cur->prev = (*root);
	(*root)->prev = NULL;
	if (cur->next)
		cur->next->prev = cur;
	(*root)->prev = NULL;
}

void	one_swap(t_stack **root, char rootname)
{
	swap(root);
	if (rootname == 'a')
		write(1, "sa\n", 3);
	else if (rootname == 'b')
		write(1, "sb\n", 3);
	position_median_tag(root);
}

void	both_swap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	position_median_tag(a);
	position_median_tag(b);
}
