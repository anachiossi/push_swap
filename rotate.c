/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:58:00 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 13:58:11 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	r(a);
	op_count(1);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	r(b);
	op_count(1);
	write(1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	r_r(a);
	op_count(1);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	r_r(b);
	op_count(1);
	write(1, "rrb\n", 4);
}
