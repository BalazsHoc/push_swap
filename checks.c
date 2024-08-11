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

#include <stdio.h> //TAKE THAT OUT

void	repeat_check(t_stack *a, char **argv, bool nargv)
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
				error_occupied(argv, nargv);
			curr = curr->next;
		}
		ref = ref->next;
		curr = ref->next;
	}
}

void	syntax_check(char **argv, bool nargv)
{
	int	i;
	int	j;

	i = 1;
	if (nargv)
		i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] != '-') && (argv[i][j] != '+')
					&& !((argv[i][j] >= 48) && (argv[i][j] <= 57)))
				free_argv(argv, nargv);
			if (j > 0 && !((argv[i][j] >= 48) && (argv[i][j] <= 57)))
				free_argv(argv, nargv);
			if (j > 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				free_argv(argv, nargv);
			j++;
		}
		j = 0;
		i++;
	}
}
