/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:29:16 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 13:59:29 by anade-mo         ###   ########.fr       */
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

void	sa(t_stack *a)
{
	s(a);
	op_count(1);
	write(1, "sa\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	p(b, a);
	op_count(1);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	p(a, b);
	op_count(1);
	write(1, "pb\n", 3);
}
