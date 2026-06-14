/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:59:56 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/13 10:13:45 by gsantoni         ###   ########.fr       */
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

void	chunk_sort(int bench, t_stack *a, t_stack *b)
{
	(void)bench;
	(void)a;
	(void)b;
}

void	radix_sort(int bench, t_stack *a, t_stack *b)
{
	(void)bench;
	(void)a;
	(void)b;
}
