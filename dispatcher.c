/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 00:00:00 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatcher(t_stack *a, t_stack *b, t_flags f)
{
	float	disorder;

	disorder = compute_disorder(a);	
	if (disorder == 0 || disorder == 1 || a->size <= 3 )
		special_sort(a, b);
	else if (disorder <= 0.2 || f.level == 1)
		bubble_sort(a, b);
	else if (disorder <= 0.5 || f.level == 2)
		chunk_sort(a, b);
	else if (disorder < 1 || f.level == 3)
		radix_sort(a, b); 
	//	quick_sort(a, b); //
}
	
	
