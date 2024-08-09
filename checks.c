/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:54:24 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 17:54:25 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int repeat_check(t_stack *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->value == n)
            return (1);
        a++;
    }
    return (0);
}
int syntax_check(char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (argv[i][j] != '-' || argv[i][j] != '+' || !(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (1);
            if (j > 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
                return (1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}
