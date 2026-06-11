/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:45:55 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/11 11:14:47 by gsantoni         ###   ########.fr       */
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
{ /*
	t_stack *a = new_stack();
	t_node	*a1 = new_node(5);
	t_node	*a2 = new_node(6);
	t_node	*a3 = new_node(7);

	push(a, a1);
	push(a, a2);
	push(a, a3);
	print_stack(a);
	r_r(a);
	print_stack(a);
	r_r(a);
	print_stack(a);
*/
	t_stack	*a = new_stack();
	t_stack	*b = new_stack();

	add_node_bottom(a, new_node(3));
	add_node_bottom(a, new_node(1));
	add_node_bottom(a, new_node(4));
	add_node_bottom(a, new_node(2));
	add_node_bottom(a, new_node(5));

	printf("before: ");
	print_stack(a);

	bubble_sort(a, b);

	printf("after:  ");
	print_stack(a);

	printf("operations: %d\n", op_count(0));

	free_stack(a);
	free_stack(b);

	/*
	t_stack *b = new_stack();
	t_node	*b1 = new_node(8);
	t_node	*b2 = new_node(9);
	t_node	*b3 = new_node(10);

	pop(a);
	pop(b);
	push(a, a1);
	push(b, b1);
	//print_stack(a);
	push(a, a2);
	push(b, b2);
	//print_stack(a);
	push(a, a3);
	push(b, b3);
	//print_stack(a);
	//r(a);
	printf("a: ");
	print_stack(a);
	printf("b: ");
	print_stack(b);
	p(a, b);
	printf("========\n");
	printf("a: ");
	print_stack(a);
	printf("b: ");
	print_stack(b);

	free_stack(a);*/

	return (0);
}
