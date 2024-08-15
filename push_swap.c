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

void	push_swap(char **argv, bool nargv)
{
	t_stack	*a;

	a = create_stack(argv, nargv);
	free_argv(argv, nargv, false);
	nargv = 0;
	repeat_check(a, argv, nargv);
	if (list_length(&a) == 2)
	{
		if (!is_sorted(&a, 'a'))
			one_swap(&a, 'a');
	}
	else if (list_length(&a) == 3)
		three_num_a(&a);

	write_stack(&a);
	stack_free(&a);
}
