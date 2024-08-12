/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:28:34 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/12 16:43:32 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> //TAKE THAT OUT

int	main(int argc, char **argv)
{
	bool	nargv;

	nargv = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		nargv = true;
	}
	syntax_check(argv, nargv);
	push_swap(argv, nargv);

	// repeat_check(*a, argv, nargv); //MAYBE we dont need that here
	// stack_free(&a);
}
