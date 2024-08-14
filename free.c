/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:58:22 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/12 16:44:06 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> //TAKE THAT OUT

void	free_argv(char **strs, bool nargv, bool error)
{
	size_t	i;

	i = 0;
	if (nargv)
	{
		while (strs[i])
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
		strs = NULL;
	}
	if (error)
	{
		write(2, "Error\n", 6);
		exit(4);
	}
}

void	stack_free(t_stack **root)
{
	t_stack	*curr;
	t_stack	*del;

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

void	error_occupied(char **argv, bool nargv)
{
	if (nargv)
		free_argv(argv, nargv, false);
	write(2, "Error\n", 6);
	exit(3);
}

void	error_stack_creation(char **argv, bool nargv, t_stack **a)
{
	stack_free(a);
	free_argv(argv, nargv, false);
	write(2, "Error\n", 6);
	exit(4);
}
