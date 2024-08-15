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
	cur = *a;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
}

t_stack	*create_stack(char **argv, bool nargv)
{
	t_stack	*new_node;
	t_stack *a;
	int		i;

	i = 0;
	if (!argv[0])
		error_occupied(argv, nargv);
	if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			error_occupied(argv, nargv);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_occupied(argv, nargv);
	new_node->value = (int)ft_atol(argv[i]);
	new_node->next = NULL;
	new_node->prev = NULL;
	a = new_node;
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			error_stack_creation(argv, nargv, &a);
		insert_end(argv, nargv, &a, ft_atol(argv[i]));
		i++;
	}
	return (a);
}
