/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:58:42 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:16:27 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **root)
{
	if (!root || !(*root))
		return ;
	*root = (*root)->next;
	(*root)->prev->next = (*root)->next;
	(*root)->prev->prev = *root;
	(*root)->next = (*root)->prev;
	if ((*root)->next)
		(*root)->next->prev = (*root)->prev;
	(*root)->prev = NULL;
	// if (root == 'a')
	// 	write(1, "sa\n", 3);
	// if (root == 'b')
	// 	write(1, "sb\n", 3);
}
