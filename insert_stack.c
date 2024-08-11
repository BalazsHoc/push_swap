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

// t_stack *insert_node(t_stack **a, int value, char **argv, bool nargv)
// {
// 	printf("hey\n");

// 	t_stack	*new_node;
// 	t_stack	*curr;

// 	new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		error_occupied(argv, nargv);
// 	new_node->value = value;
// 	new_node->next = NULL;
// 	printf("HI\n");

// 	if (a == NULL)
// 	{
// 		a = new_node;
// 		new_node->prev = NULL;
// 	}
// 	else
// 	{
// 		curr = a;
// 		while (curr->next != NULL)
// 			curr = curr->next;
// 		curr->next = new_node;
// 		new_node->prev = curr;
// 	}
// }

t_stack	*create_stack(char **argv, bool nargv)
{
	int		i;
	t_stack	*a;
	t_stack	*cur;
	t_stack	*buf;

	i = 1;
	buf = NULL;
	a = NULL;
	while (argv[i - nargv])
	{
		if (atol(argv[i - nargv]) > INT_MAX || atol(argv[i - nargv]) < INT_MIN)
			error_occupied(argv, nargv);
		cur = malloc(sizeof(t_stack) * 1);
		if (!cur)
			error_occupied(argv, nargv);
		cur->value = atol(argv[i - nargv]);
		cur->next = NULL;
		if (i == 1)
			a = cur;
		else if (buf)
			cur->prev = buf;
		buf = cur;
		i++;
	}
	return (a);
}
