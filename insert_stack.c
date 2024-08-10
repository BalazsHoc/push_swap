/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:35:36 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/10 14:29:07 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_node(t_stack **a, int value, char **argv, bool if_new_argv)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_occupied(a, argv, if_new_argv);
	new_node->value = value;
	new_node->next = NULL;
	curr = *a;
	if (*a == NULL)
	{
		*a = new_node;
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

void	create_stack(t_stack **a, char **argv, bool if_new_argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_occupied(a, argv, if_new_argv);
		insert_node(a, (int)n, argv, if_new_argv);
		i++;
	}
}
