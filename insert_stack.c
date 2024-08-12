/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:35:36 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/11 20:04:22 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> //TAKE THAT OUT
#include <stdlib.h> //TAKE THAT OUT

// static t_stack	**first_node(t_stack *last_node)
// {
// 	t_stack **first_node;

// 	first_node = &last_node;
// 	while ((*first_node)->prev)
// 		*first_node = (*first_node)->prev;
// 	return (first_node);
// }

static void	insert_end(char **argv, bool nargv, t_stack **a, int value)
{
	t_stack	*new_node;
	t_stack	*cur;

	printf("HERE1\n");
	cur = *a; //THIS IS HERE THE PROBLEM
	// if (!a)
	// 	return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_stack_creation(argv, nargv, a);
	new_node->value = value;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		printf("new->value: %d\n", new_node->value);
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
		new_node->prev = cur;
	}
}

t_stack	**create_stack(char **argv, bool nargv)
{
	t_stack	**root;
	int		i;

	root = NULL;
	i = 1;
	while (argv[i - nargv])
	{
		if (atol(argv[i - nargv]) > INT_MAX || atol(argv[i - nargv]) < INT_MIN)
			error_stack_creation(argv, nargv, root);
		insert_end(argv, nargv, root, atol(argv[i - nargv]));
	}
	return (root);
}
