/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:29:22 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/13 10:17:27 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}	t_stack;

//level if 0 == adaptive, 1 == simple, 2 == medium, 3 == complex
//bench is boolean 1 if --bench is set, 0 otherwise
typedef struct s_flags
{
	int		level;
	int		bench;
}	t_flags;

// parsing — parse.c (ft_atoi from libft)
int		is_valid(char *s);
int		input_to_stack(char **arg, t_stack *a);
int		assign_flags(t_flags *f, char **argv, int argc);
void	benchmode(float d, int *n);

// stack creation — stack.c
t_node	*new_node(int value);
t_stack	*new_stack(void);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

//stack manipulation — stack_utils.c
void	push(t_stack *stack, t_node *new);
t_node	*pop(t_stack *stack);
void	push_bottom(t_stack *stack, t_node *new);
t_node	*pop_bottom(t_stack *stack);

//base operations — operations_base.c
int		*op_count(int k);
void	p(t_stack *x, t_stack *y);
void	r(t_stack *x);
void	r_r(t_stack *x);
void	s(t_stack *x);

//push swap operations — operations_ps.c
void	sa(int bench, t_stack *a);
void	sb(int bench, t_stack *b);
void	ss(int bench, t_stack *a, t_stack *b);
void	pa(int bench, t_stack *a, t_stack *b);
void	pb(int bench, t_stack *a, t_stack *b);

// rotate operations — operations_r.c
void	ra(int bench, t_stack *a);
void	rb(int bench, t_stack *b);
void	rr(int bench, t_stack *a, t_stack *b);

// reverse rotate operations — operations_rr.c
void	rra(int bench, t_stack *a);
void	rrb(int bench, t_stack *b);
void	rrr(int bench, t_stack *a, t_stack *b);

//adaptive algorithm — dispatcher.c
void	dispatcher(t_stack *a, t_stack *b, t_flags f);
float	disorder(t_stack *h);

//sorting — sort.c
void	bubble_sort(int bench, t_stack *a, t_stack *b);
void	chunk_sort(int bench, t_stack *a, t_stack *b); // to do
void	radix_sort(int bench, t_stack *a, t_stack *b); // to do

//sorting — sort_special.c
void	special_sort(int bench, t_stack *a, t_stack *b); //to do
void	sort_2(t_stack *a, t_stack *b); //to do
void	sort_3(t_stack *a, t_stack *b); //to do
void	sort_inverted(t_stack *a, t_stack *b); //to do 

#endif
