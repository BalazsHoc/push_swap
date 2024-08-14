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

// static void	write_stack(t_stack **root)
// {
// 	t_stack	*cur;

// 	cur = *root;
// 	while (cur != NULL)
// 	{
// 		printf("cur->value: %d\n", cur->value);
// 		cur = cur->next;
// 	}
// }

void	push_swap(char **argv, bool nargv)
{
	t_stack	*a;

	a = create_stack(argv, nargv);
	free_argv(argv, nargv, false);
	nargv = 0;
	repeat_check(a, argv, nargv);
	


	stack_free(&a);
}
