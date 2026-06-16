/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:48:54 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/14 13:47:57 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  SWAP (swap n1 and n2 of x)
  sa  → swap top 2 elements of a
  sb  → swap top 2 elements of b

  PUSH  (top x -> top x)
  pa  → take top of b, push to top of a
  pb  → take top of a, push to top of b

  ROTATE  (top x → bottom x)
  ra  → top of a goes to bottom of a
  rb  → top of b goes to bottom of b

  REVERSE ROTATE  (bottom x → top x)
  rra → bottom of a goes to top of a
  rrb → bottom of b goes to top of b
*/

#include "push_swap.h"

int	find_min(t_stack *x)
{
	int		min;
	t_node	*current;

	min = x->top->value;
	current = x->top->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

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

void	min_top(int bench, t_stack *a)
{
	int		min;
	int		pos;
	t_node	*cur;

	min = find_min(a);
	pos = 0;
	cur = a->top;
	while (cur->value != min)
	{
		pos++;
		cur = cur->next;
	}
	if (pos <= a->size / 2)
		while (a->top->value != min)
			ra(bench, a);
	else
		while (a->top->value != min)
			rra(bench, a);
}

void	selection_sort(int bench, t_stack *a, t_stack *b)
{
	while (a->size > 3 && !is_sorted(a))
	{
		min_top(bench, a);
		pb(bench, a, b);
	}
	if (a->size == 2)
		sort_2(bench, a);
	else if (a->size == 3)
		sort_3(bench, a);
	while (b->size)
		pa(bench, a, b);
}
