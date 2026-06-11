/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:29:22 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/10 20:21:52 by gsantoni         ###   ########.fr       */
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
t_stack	*new_stack(void);
void	free_stack(t_stack *stack);
void	add_node_top(t_stack *stack, t_node *new);
void	add_node_bottom(t_stack *stack, t_node *new);
void	p(t_stack *x, t_stack *y);

#endif