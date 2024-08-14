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


#include <stdio.h>


typedef struct s_stack
{
	int		value;

	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//function we have used

//checks.c
void	repeat_check(t_stack *a, char **argv, bool nargv);
void	syntax_check(char **argv, bool nargv);


//free.c
void	free_argv(char **strs, bool nargv, bool error);
void	stack_free(t_stack **root);
void	error_occupied(char **argv, bool nargv);
void	error_stack_creation(char **argv, bool nargv, t_stack **a);

//ft_atol.c
long	ft_atol(const char *nptr);

//ft_split.c
char	**ft_split(char *s);

//implementation.c
bool	is_sorted(t_stack **root, char root_name);
size_t  list_length(t_stack **root);

//insert_stack.c
t_stack	*create_stack(char **argv, bool nargv);

//main.c
int	main(int argc, char **argv);

//push_swap.c
void    push_swap(char **argv, bool nargv);

//push.c
void	push(t_stack **dest, t_stack **src);

//rotate.c
void	rotate(t_stack **root);

//reverse_rotate.c
void	reverse_rotate(t_stack **root);

//swap.c
void	swap(t_stack **root);


#endif
