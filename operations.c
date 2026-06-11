/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:32:09 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/11 11:26:10 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// push, for pa, pb
void	p(t_stack *x, t_stack *y)
{
	push(y, pop(x));
}

void	r(t_stack *x)
{
	t_node	*temp;

	if (!x || x->size < 2)
		return ;
	temp = pop(x);
	x->bottom->next = temp;
	x->bottom = temp;
	temp->next = NULL;
	x->size += 1;
}

void	r_r(t_stack *x)
{
	t_node	*temp;

	if (!x || x->size < 2)
		return ;
	temp = x->top;
	while (temp->next != x->bottom)
		temp = temp->next;
	push(x, x->bottom);
	temp->next = NULL;
	x->bottom = temp;
	x->size -= 1;
}

void	s(t_stack *x)
{
	t_node	*a;
	t_node	*b;

	a = pop(x);
	b = pop(x);
	push(x, a);
	push(x, b);
}


/* reverse, for ra, rb
void	r(t_stack *x)
{
	t_node	*temp;

	if (!x || x->size < 2)
		return ;
	temp = x->top;
	x->top = temp->next;
	x->bottom->next = temp;
	x->bottom = temp;
	temp->next = NULL;
}
// reverse rotate, for rra rrb
void	r_r(t_stack *x)
{
	t_node	*temp;
	t_node	*new_bottom;

	if (x->size < 2)
		return ;
	new_bottom = x->top;
	while (new_bottom->next != x->bottom)
		new_bottom = new_bottom->next;
	temp = x->bottom;
	new_bottom->next = NULL;
	x->bottom = new_bottom;
	temp->next = x->top;
	x->top = temp;
}
//se ci fosse un prev
void	reverse_rotate2(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->bottom;
	x->bottom = temp->prev;
	x->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = x->top;
	x->top->prev = temp;
	x->top = temp;
}

// for sa, sb
void	s(t_stack *x)
{
	t_node	*temp;

	if (x->size < 2)
		return ;
	temp = x->top;
	x->top = temp->next;
	temp->next = x->top->next;
	x->top->next = temp;
	if (!temp->next)
		x->bottom = temp;
}*/
