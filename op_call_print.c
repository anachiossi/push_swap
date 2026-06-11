/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_call_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:29:16 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 11:15:27 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	op_count(int add)
{
	static int	count = 0;

	count += add;
	return (count);
}

void	pa(t_stack *a, t_stack *b)
{
	p(b, a);
	op_count(1);
	write(1,"pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	p(a, b);
	op_count(1);
	write(1,"pb\n", 3);
}

void	sa(t_stack *a)
{
	s(a);
	op_count(1);
	write(1,"sa\n", 3);
}

void	ra(t_stack *a)
{
	r(a);
	op_count(1);
	write(1,"ra\n", 3);
}

void	rb(t_stack *b)
{
	r(b);
	op_count(1);
	write(1,"rb\n", 3);
}

void	rra(t_stack *a)
{
	r_r(a);
	op_count(1);
	write(1,"rra\n", 4);
}

void	rrb(t_stack *b)
{
	r_r(b);
	op_count(1);
	write(1,"rrb\n", 4);
}
