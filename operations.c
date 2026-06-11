/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:32:09 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/11 09:51:36 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	p(t_stack *x, t_stack *y)
{
	push(y, pop(x));
}

void	r(t_stack *x)
{
	t_node	*temp;

	if (!x || x->size < 2)
		return ;
	temp = x->top;
	x->top = temp->next;
	x->bottom->next = temp;
	x->bottom = temp;
	temp->next = NULL;
}
