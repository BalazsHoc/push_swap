/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:28:34 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/15 19:15:29 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	bool	nargv;
	char	**arr;

	nargv = false;
	if (argc == 1)
		exit(0);
	if ((argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (!argv[2])
	{
		arr = ft_split(argv[1]);
		nargv = true;
	}
	else
		arr = argv + 1;
	syntax_check(arr, nargv);
	push_swap(arr, nargv);
	return (0);
}
