/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 08:52:04 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/21 16:36:43 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	my_sqrt(int n)
{
	int	k;

	k = 0;
	while (k * k < n)
		k++;
	if (k * k == n)
		return (k);
	else
		return (k - 1);
}

void	chunk_sort(int bench, t_stack *a, t_stack *b)
{
	int	i;
	int	k;
	int	len;

	len = my_sqrt(a->size);
	k = (a->size - 1) / len + 1;
	while (--k >= 0)
	{
		i = 0;
		while (i++ < a->size + b->size)
		{
			if (a->top->rank >= k * len && a->top->rank < (k + 1) * len)
				pb(bench, a, b);
			else
				ra(bench, a);
		}
		while (b->size)
		{
			max_to_top(bench, b);
			pa(bench, a, b);
		}
	}
	while (a->top->rank != 0)
		ra(bench, a);
}
