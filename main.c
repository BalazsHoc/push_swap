/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:28:34 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 17:28:36 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack **a;
    t_stack **b;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (NULL);
    if (argc == 2)
        argv = ft_split(argv[1], 32);
    
    create_stack(a, argv);
}