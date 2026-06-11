/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:14:12 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 11:24:04 by anade-mo         ###   ########.fr       */
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


