/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:28:34 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/10 14:26:35 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	bool	if_new_argv;

	if_new_argv = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		if_new_argv = true;
	}
	syntax_check(argv, if_new_argv);
	create_stack(a, argv, if_new_argv);
	repeat_check(a, argv, if_new_argv);
}
