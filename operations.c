/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:32:09 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/10 21:48:06 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	p(t_stack *x, t_stack *y)
{	
	t_node	*temp;

	if (!x->size)
		return ;
	temp = x->top;
	x->top = temp->next;
	if (x->size == 1)
		x->bottom = NULL;
	temp->next = y->top;
	if (!y->size)
		y->bottom = temp;
	y->top = temp;
	y->size += 1;
	x->size -= 1;
}
