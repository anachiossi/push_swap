/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:48:54 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/19 18:22:11 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	min_to_top(int bench, t_stack *a)
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

int	find_max(t_stack *x)
{
	int		max;
	t_node	*current;

	max = x->top->value;
	current = x->top->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	max_to_top(int bench, t_stack *b)
{
	int		max;
	int		pos;
	t_node	*cur;

	max = find_max(b);
	pos = 0;
	cur = b->top;
	while (cur->value != max)
	{
		pos++;
		cur = cur->next;
	}
	if (pos <= b->size / 2)
		while (b->top->value != max)
			rb(bench, b);
	else
		while (b->top->value != max)
			rrb(bench, b);
}
