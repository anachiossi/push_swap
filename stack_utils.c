/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:56:51 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/12 17:30:09 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (!stack->size)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->next = stack->top;
		stack->top = new;
	}
	stack->size += 1;
}

t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->size)
		return (NULL);
	temp = stack->top;
	stack->top = temp->next;
	temp->next = NULL;
	if (stack->bottom == temp)
		stack->bottom = NULL;
	stack->size -= 1;
	return (temp);
}