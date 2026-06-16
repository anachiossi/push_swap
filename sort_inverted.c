/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inverted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:32:27 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/16 20:22:38 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_inverted(int bench, t_stack *a, t_stack *b)
{
	int	n;

	if (a->size == 2)
		return (sort_2(bench, a));
	if (a->size == 3)
		return (sort_3(bench, a));
	n = a->size - 4;
	sa(bench, a);
	while (n > 0)
	{
		rra(bench, a);
		pb(bench, a, b);
		n--;
	}
	ra(bench, a);
	ra(bench, a);
	sa(bench, a);
	while (b->size > 0)
		pa(bench, a, b);
}
