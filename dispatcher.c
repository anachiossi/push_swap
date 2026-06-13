/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/13 10:18:51 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_stack *x)
{
	int			m;
	int			p;
	t_node		*a;
	t_node		*b;

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

void	dispatcher(t_stack *a, t_stack *b, t_flags f)
{
	float	d;

	d = disorder(a);
	if (d == 0 || a->size <= 3)
		special_sort(f.bench, a, b, d);
	else if (d <= 0.2 || f.level == 1)
		bubble_sort(f.bench, a, b);
	else if (d <= 0.5 || f.level == 2)
		chunk_sort(f.bench, a, b);
	else if (d < 1 || f.level == 3)
		radix_sort(f.bench, a, b);
}
//quick_sort(a, b);