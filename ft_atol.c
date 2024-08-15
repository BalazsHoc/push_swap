/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:14:39 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:22:51 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr)
		return (0);
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
