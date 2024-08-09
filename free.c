/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:58:22 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 18:58:24 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack **root)
{
	t_stack *curr;
	t_stack *del;

    if (!root)
        return ;
	curr = *root;
	del = curr;
	while (curr != NULL)
	{
        del = curr;
		curr = curr->next;
		free(del);
	}
	*root = NULL;
}