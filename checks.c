/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:54:24 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/10 14:33:06 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_check(t_stack *a, char **argv, bool if_new_argv)
{
	t_stack	*curr;
	t_stack	*ref;

	curr = a;
	ref = curr;
	curr = curr->next;
	while (ref->next)
	{
		while (curr)
		{
			if (ref->value == curr->value)
				error_occupied(a, argv, if_new_argv);
			curr = curr->next;
		}
		ref = ref->next;
		curr = ref->next;
	}
}

void	syntax_check(char **argv, bool new_argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] != '-' || argv[i][j] != '+')
						|| (!(argv[i][j] >= '0') && !(argv[i][j] <= '9')))
				free_argv(argv, new_argv);
			if (j > 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				free_argv(argv, new_argv);
			j++;
		}
		j = 0;
		i++;
	}
}
