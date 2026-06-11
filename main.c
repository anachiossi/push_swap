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
void	print_ranks(t_stack *stack)
{
	t_node		*temp;

	if (!stack->size)
		return ;
	temp = stack->top;
	while (temp)
	{
		printf("%d ", temp->rank);
		temp = temp->next;
	}
	printf("\n");
}


int	main(int argc, char **argv)
{
	int		*arr;
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_flags	f;

	if (argc < 2)
		return (0);
	i = assign_flags(&f, argv, argc);
	arr = input_to_array(argc - i, argv + i);
	if (!arr)
		return (write(2, "Error\n", 6), 1);
	a = build_input_stack(arr, argc - i);
	b = new_stack();
	if (!a || !b)
		return (free(arr), free_stack(a), free_stack(b), write(2, "Error\n", 6), 1);
	assign_ranks(a, arr, argc - i);
	float disorder = compute_disorder(a);
	printf("before: ");
	print_stack(a);
	printf("rank order:");
	print_ranks(a);
	printf("disorder: %.2f\n", disorder);
	
	dispatcher(a, b, f);

	printf("after:  ");
	print_stack(a);
	printf("rank order:");
	print_ranks(a);
	printf("disorder: %.2f\n", compute_disorder(a));

	printf("operations: %d\n", op_count(0));

	free_stack(a);
	free_stack(b);
	free(arr);
	return (0);
}

/*
	assign_ranks(a, arr, argc - 1);
	disorder = compute_disorder(a);
	if (disorder == 0)
		return (free_stack(a), free_stack(b), 0);
	dispatcher(a, b, disorder);
	free(arr);
	free_stack(a);
	free_stack(b);
	return (0);
*/
