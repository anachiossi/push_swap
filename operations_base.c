/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:32:09 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/13 10:10:44 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

//order sa sb ss pa pb ra rb rr rra rrb rrr. total 11
int	*op_count(int k)
{
	static int	n[12];

	n[k] += 1;
	n[11] += 1;
	return (n);
}

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
