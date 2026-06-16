/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/16 21:08:46 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_stack *x)
{
	int		m;
	int		p;
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

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	adaptive_sort(t_stack *a, t_stack *b, t_ps_flags f)
{
	float	d;
	float	t;
	int		n;

	n = a->size;
	d = disorder(a);
	if (d == 1.0)
		return (sort_inverted(f.bench, a, b));
	if (n <= 100)
		return (selection_sort(f.bench, a, b));
	if (n > 300)
		return (radix_sort(f.bench, a, b));
	t = 0.1;
	if (n <= 150)
		t = 0.2;
	else if (n <= 200)
		t = 0.15;
	if (d < t || d > 1.0 - t)
		selection_sort(f.bench, a, b);
	else
		radix_sort(f.bench, a, b);
}

void	dispatcher(t_stack *a, t_stack *b, t_ps_flags f)
{
	if (is_sorted(a))
		return ;
	if (f.level == 0)
		adaptive_sort(a, b, f);
	else if (f.level == 1)
		selection_sort(f.bench, a, b);
	else if (f.level == 2)
		chunk_sort(f.bench, a, b);
	else if (f.level == 3)
		radix_sort(f.bench, a, b);
}
