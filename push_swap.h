/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:29:22 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/11 11:13:39 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node {
	int				value;
	int				rank;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	t_node		*top;
	t_node		*bottom;
	int			size;
} t_stack;

// parsing — parse.c (ft_atoi from libft)
int		validate_input(char **argv);
int		validate_int_limits(char **argv);
int		*input_to_array(int argc, char **argv);
int		validate_int_duplicates(int *arr, int size);

// stack creation — stack.c
t_node	*new_node(int value);
t_stack	*new_stack(void);
t_stack	*build_input_stack(int *arr, int size);
void	assign_ranks(t_stack *a, int *arr, int size);
void	free_stack(t_stack *stack);

//stack manipulation — stack_utils.c
void	push(t_stack *stack, t_node *new);
void	push_bottom(t_stack *stack, t_node *new);
t_node	*pop(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

//base operations — operations.c
void	p(t_stack *x, t_stack *y);
void	r(t_stack *x);
void	r_r(t_stack *x);
void	s(t_stack *x);

//push swap operations — print_count.c
int		op_count(int add);
void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

//rotate operations — rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);

//adaptive algorithm — dispatcher.c
void	dispatcher(t_stack *a, t_stack *b, float disorder);

//disorder computation — disorder.c
float	compute_disorder(t_stack *h);

//sorting — easy_sort.c
void	bubble_sort(t_stack *a, t_stack *b);

#endif
