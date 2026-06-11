/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:48:54 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 20:11:26 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_sort(t_stack *a, t_stack *b)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (disorder == 0)
		return ;
	else if (disorder == 1)
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
