/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:58:00 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/21 23:42:43 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int bench, t_stack *a)
{
	r(a);
	op_count(5);
	if (!bench)
		write(1, "ra\n", 3);
}

void	rb(int bench, t_stack *b)
{
	r(b);
	op_count(6);
	if (!bench)
		write(1, "rb\n", 3);
}

void	rr(int bench, t_stack *a, t_stack *b)
{
	r(a);
	r(b);
	op_count(7);
	if (!bench)
		write(1, "rr\n", 3);
}
