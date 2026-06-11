/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:47:47 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/11 13:04:20 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *x)
{
	int	m;
	int	p;
	t_node	*a;
	t_node	*b;

	if (!x || x->size < 2)
		return ((float)0);
	p = 0;
	m = 0;
	a = x->top;
	while (a->next)
	{
		b = a->next;
		while (b)
		{
			p += 1;
			m += (a->value > b->value);
			b = b->next;
		}
		a = a->next;
	}
	return ((float)m / (float)p);
}
