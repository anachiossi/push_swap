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

void	dispatcher(t_stack *a, t_stack *b, float disorder, t_list flag)
{
	if (disorder == 0 || disorder == 1 || a->size <= 3)
		special_cases(a, b, disorder);
	else if (disorder <= 0.2 || flag.simple == 1)
		bubble_sort(a, b);
	else if (disorder <= 0.5 || flag.medium == 1)
		chunk_sort(a, b);
	else if (disorder < 1 || flag.complex == 1)
		radix_sort(a, b); 
	//	quick_sort(a, b); //
}
	
	
