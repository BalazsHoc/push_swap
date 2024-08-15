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

int	main(int argc, char **argv)
{
	bool	nargv;
	char **arr;

	nargv = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(0);
	if (!argv[2])
	{
		arr = ft_split(argv[1]);
		nargv = true;
	}
	else
		arr = argv + 1;
	syntax_check(arr, nargv);
	push_swap(arr, nargv);

}
