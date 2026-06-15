/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:59:56 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/15 18:06:19 by gsantoni         ###   ########.fr       */
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

static void	radix_iter(int bench, unsigned int n, t_stack *a, t_stack *b)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (!(((unsigned int)a->top->value >> n) & 1))
			pb(bench, a, b);
		else
			ra(bench, a);
		i++;
	}
	while (b->size)
		pa(bench, a, b);
}

void	chunk_sort(int bench, t_stack *a, t_stack *b)
{
	(void)bench;
	(void)a;
	(void)b;
}

void	radix_sort(int bench, t_stack *a, t_stack *b)
{
	unsigned int	n;
	unsigned int	p;
	unsigned int	digits;
	int				m;
	t_node			*temp;

	temp = a->top;
	m = temp->value;
	while (temp)
	{
		m = (temp->value) * (temp->value > m) + m * (m > temp->value);
		temp = temp->next;
	}
	digits = 0;
	p = 1;
	while ((unsigned int)m / p)
	{
		p *= 2;
		digits++;
	}
	n = 0;
	while (n < digits)
		radix_iter(bench, n++, a, b);
}
