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

	cur = NULL;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_stack_creation(argv, nargv, a);
	new_node->value = value;
	new_node->next = NULL;
	if (*a == NULL)
	{
		printf("new->value: %d\n", new_node->value);
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		printf("new->value: %d\n", new_node->value);
		cur = *a;
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
		new_node->prev = cur;
		printf("cur->prev->value: %d\n", cur->prev->value);
		printf("new->prev->value: %d\n", new_node->prev->value);
	}
}

void	create_stack(char **argv, t_stack **a, bool nargv)
{
	int		i;

	i = 1;
	while (argv[i - nargv])
	{
		printf("%d\n", i);
		if (atol(argv[i - nargv]) > INT_MAX || atol(argv[i - nargv]) < INT_MIN)
			error_stack_creation(argv, nargv, a);
		insert_end(argv, nargv, a, atol(argv[i - nargv]));
		printf("(*a)->value: %d\n", (*a)->value);
		i++;
	}
}
