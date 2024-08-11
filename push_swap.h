/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:18:53 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:25:48 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;

	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//function we have used
void	repeat_check(t_stack *a, char **argv, bool nargv);
void	syntax_check(char **argv, bool nargv);

void	free_argv(char **strs, bool nargv);
void	stack_free(t_stack **root);
void	error_occupied(char **argv, bool nargv);

long	ft_atol(const char *nptr);

char	**ft_split(char *s, char c);

t_stack	*create_stack(char **argv, bool nargv);

int	main(int argc, char **argv);

void	push(t_stack **dest, t_stack **src);

void	rotate(t_stack **root);

void	reverse_rotate(t_stack **root);

void	swap(t_stack **root);


#endif
