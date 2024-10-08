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
				error_stack_creation(argv, nargv, &a);
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
	int	n;

	i = 0;
	while (argv[i])
	{
		j = 0;
		n = 0;
		if (argv[i][n] && n == 0 && (argv[i][n] == '-' || argv[i][n] == '+'))
			n++;
		while (argv[i][n] && argv[i][n] == '0')
			n++;
		while (argv[i][n + j])
		{
			if (argv[i][n + j] < '0' || argv[i][n + j] > '9')
				free_argv(argv, nargv, true);
			j++;
		}
		if (j > 11)
			free_argv(argv, nargv, true);
		i++;
	}
}
