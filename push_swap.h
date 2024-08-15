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


#include <stdio.h>	// TAKE THAT OUT


typedef struct s_stack
{
	int		value;
	int		target_value;
	int		position;

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
long	ft_atol(char *nptr);

//ft_split.c
char	**ft_split(char *s);

//implementation_utils.c
int		smallest_value(t_stack **a);
int		target_value(t_stack **a, t_stack *cur_b);
void	positions(t_stack **a, t_stack **b);

//implementation.c
void    three_num_a(t_stack **root);
void    push_swap_algorithm(t_stack **a);

//insert_stack.c
t_stack	*create_stack(char **argv, bool nargv);

//main.c
int	main(int argc, char **argv);

//push_swap.c
void    push_swap(char **argv, bool nargv);

//push.c
void	push(t_stack **dest, t_stack **src, char destname);

//rotate.c
void	one_rotate(t_stack **root, char rootname);
void	both_rotate(t_stack **a, t_stack **b);

//reverse_rotate.c
void	one_reverse_rotate(t_stack **root, char rootname);
void	both_reverse_rotate(t_stack **a, t_stack **b);

//swap.c
void	one_swap(t_stack **root, char rootname);
void	both_swap(t_stack **a, t_stack **b);

//stack_utils.c
void	write_stack(t_stack **root);	//TAKE THAT OUT
size_t  list_length(t_stack **root);
bool    is_sorted(t_stack **root, char root_name);


#endif
