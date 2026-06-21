/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:13:05 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/21 23:42:44 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int bench, t_stack *a)
{
	r_r(a);
	op_count(8);
	if (!bench)
		write(1, "rra\n", 4);
}

void	rrb(int bench, t_stack *b)
{
	r_r(b);
	op_count(9);
	if (!bench)
		write(1, "rrb\n", 4);
}

void	rrr(int bench, t_stack *a, t_stack *b)
{
	r_r(a);
	r_r(b);
	op_count(10);
	if (!bench)
		write(1, "rrr\n", 4);
}
