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

t_stack	*build_input_stack(int *arr, int size)
{
	t_stack	*a;
	t_node	*new;
	int		i;
	
	a = new_stack();
	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new = new_node(arr[i]);
		if (!new)
		{
			free_stack(a);
			return (NULL);
		}
		push_bottom(a, new);
		i++;
	}
	return (a);
}

void	assign_ranks(t_stack *a, int *arr, int size)
{
	int rank;
	t_node	*temp;
	int i;
	int j;

	temp = a->top;
	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (arr[i] > arr[j])
				rank++;
			j++;
		}
		temp->rank = rank;
		temp = temp->next;
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
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
