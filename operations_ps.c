/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:29:16 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/21 23:42:42 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int bench, t_stack *a)
{
	s(a);
	op_count(0);
	if (!bench)
		write(1, "sa\n", 3);
}

void	sb(int bench, t_stack *b)
{
	s(b);
	op_count(1);
	if (!bench)
		write(1, "sb\n", 3);
}

void	ss(int bench, t_stack *a, t_stack *b)
{
	s(a);
	s(b);
	op_count(2);
	if (!bench)
		write(1, "ss\n", 3);
}

void	pa(int bench, t_stack *a, t_stack *b)
{
	p(b, a);
	op_count(3);
	if (!bench)
		write(1, "pa\n", 3);
}

void	pb(int bench, t_stack *a, t_stack *b)
{
	p(a, b);
	op_count(4);
	if (!bench)
		write(1, "pb\n", 3);
}
