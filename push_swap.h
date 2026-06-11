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

typedef struct s_node {
	int				value;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	t_node		*top;
	t_node		*bottom;
	int			size;
} t_stack;

t_node	*new_node(int value);
t_node	*pop(t_stack *stack);
t_stack	*new_stack(void);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, t_node *new);
void	add_node_bottom(t_stack *stack, t_node *new);
void	p(t_stack *x, t_stack *y);
int		op_count(int add);
void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	r(t_stack *x);
void	r_r(t_stack *x);
void	s(t_stack *x);
void	bubble_sort(t_stack *a, t_stack *b);

#endif
