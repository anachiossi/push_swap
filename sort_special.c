/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:48:54 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/12 18:45:28 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_sort(int bench, t_stack *a, t_stack *b)
{
	float	d;

	d = disorder(a);
	if (d == 0)
		return ;
	else if (d == 1)
		sort_inverted(a, b);
	else if (a->size == 2)
		sort_2(a, b);
	else if (a->size == 3)
		sort_3(a, b);
}

void	sort_2(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

void	sort_3(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

void	sort_inverted(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
