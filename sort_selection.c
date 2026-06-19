/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:48:54 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/19 18:07:51 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(int bench, t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(bench, a);
}

void	sort_3(int bench, t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->bottom->value;
	if (top < mid && mid < bot)
		return ;
	if (top > mid && top > bot && mid < bot)
		ra(bench, a);
	else if (top > mid && top > bot && mid > bot)
	{
		sa(bench, a);
		rra(bench, a);
	}
	else if (top < mid && top < bot)
	{
		rra(bench, a);
		sa(bench, a);
	}
	else if (top > mid)
		sa(bench, a);
	else
		rra(bench, a);
}

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

void	selection_sort(int bench, t_stack *a, t_stack *b)
{
	while (a->size > 3 && disorder(a) != 0)
	{
		min_to_top(bench, a);
		pb(bench, a, b);
	}
	if (a->size == 2)
		sort_2(bench, a);
	else if (a->size == 3)
		sort_3(bench, a);
	while (b->size)
		pa(bench, a, b);
}
