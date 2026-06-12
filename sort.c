/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:59:56 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/12 16:00:57 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		n;

	while (a->size > 1)
	{
		i = 0;
		n = a->size - 1;
		while (i < n)
		{
			if (a->top->value < a->top->next->value)
				sa(a);
			ra(a);
			i++;
		}
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

void	radix_sort(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}