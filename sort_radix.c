/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:59:56 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/21 23:42:48 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_iter(int bench, unsigned int n, t_stack *a, t_stack *b)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (!(((unsigned int)a->top->rank >> n) & 1))
			pb(bench, a, b);
		else
			ra(bench, a);
		i++;
	}
	while (b->size)
		pa(bench, a, b);
}

void	radix_sort(int bench, t_stack *a, t_stack *b)
{
	unsigned int	n;
	unsigned int	p;
	unsigned int	digits;

	if (a->size <= 1)
		return ;
	digits = 0;
	p = (unsigned int)(a->size - 1);
	while (p)
	{
		p >>= 1;
		digits++;
	}
	n = 0;
	while (n < digits)
		radix_iter(bench, n++, a, b);
}
