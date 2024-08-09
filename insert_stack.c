/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:35:36 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 17:35:38 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_node(t_stack **root, int value)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	curr = *root;
	if (*root == NULL)
	{
		*root = new_node;
		new_node->prev = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
		new_node->prev = curr;
	}
}

void	create_stack(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n =  atol(argv[i]);
		if (n > INT_MAX || n  < INT_MIN)
		


		insert_node(a, (int)n);
		i++;
	}
}