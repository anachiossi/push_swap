/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:45:55 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/10 21:49:40 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stack(t_stack *stack)
{
	t_node		*temp;

	if (!stack->size)
		return ;
	temp = stack->top;
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int		main(void)
{
	t_stack *a = new_stack();
	t_node	*a1 = new_node(5);
	t_node	*a2 = new_node(6);

	t_stack *b = new_stack();
	t_node	*b1 = new_node(7);
	t_node	*b2 = new_node(8);

	append(a, a1);
	append(a, a2);
	append(b, b1);
	append(b, b2);

	printf("a: ");
	print_stack(a);
	printf("b: ");
	print_stack(b);

	p(a, b);

	printf("======\n");
	
	printf("a: ");
	print_stack(a);
	printf("b: ");
	print_stack(b);
	
	free_stack(a);
	free_stack(b);
	
	return (0);
}