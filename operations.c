/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:32:09 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/12 17:28:36 by gsantoni         ###   ########.fr       */
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
	push_bottom(x, temp);
}

void	r_r(t_stack *x)
{
	t_node	*temp;

	if (!x || x->size < 2)
		return ;
	temp = pop_bottom(x);
	push(x, temp);
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