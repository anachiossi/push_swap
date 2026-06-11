/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:42:37 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/11 10:10:09 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node		*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack		*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

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

//non penso che ci serva
void	add_node_bottom(t_stack *stack, t_node *new)
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

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack->size)
	{
		free(stack);
		return ;
	}
	temp = stack->top;
	stack->top = temp->next;
	stack->size -= 1;
	free(temp);
	free_stack(stack);
}
