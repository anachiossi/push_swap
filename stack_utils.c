/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:56:51 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 13:57:02 by anade-mo         ###   ########.fr       */
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

// non penso che ci serva
void	push_bottom(t_stack *stack, t_node *new)
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
		stack->bottom->next = new;
		stack->bottom = new;
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

// still uses a while, has to find the prev to bottom on every move
t_node	*pop_bottom(t_stack *stack)
{
	t_node	*temp;
	t_node	*new_bottom;

	if (!stack || !stack->size)
		return (NULL);
	if (stack->size == 1)
		return (pop(stack));
	new_bottom = stack->top;
	while (new_bottom->next != stack->bottom)
		new_bottom = new_bottom->next;
	temp = stack->bottom;
	new_bottom->next = NULL;
	stack->bottom = new_bottom;
	stack->size -= 1;
	return (temp);
}
