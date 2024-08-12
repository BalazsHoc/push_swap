/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:51:52 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/12 16:42:40 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> //TAKE THAT OUT

static void	write_stack(t_stack **root)
{
	t_stack	*cur;

	cur = *root;
	while (cur)
	{
		printf("cur: %d\n", cur->value);
		cur = cur->next;
	}
}

void	push_swap(char **argv, bool nargv)
{
	t_stack	**a;

	a = create_stack(argv, nargv);
	free_argv(argv, nargv, false);
	write_stack(a);

	//stack_free(a);
}
