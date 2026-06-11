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
#include <stdlib.h>
#include <unistd.h>
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
int	main(int argc, char **argv)
{
	int		*arr;
	float	disorder;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (validate_input(argv) == -1 || input_to_array(argc, argv) == NULL)
		return (write(2, "Error\n", 6), 1);
	arr = input_to_array(argc, argv);
	a = build_input_stack(arr, argc - 1);
	b = new_stack();
	if (!a || !b)
		return (free(arr), free_stack(a), free_stack(b), write(2, "Error\n", 6), 1);
	disorder = compute_disorder(a);
	printf("before: ");
	print_stack(a);
	printf("disorder: %.2f\n", disorder);

	bubble_sort(a, b);

	printf("after:  ");
	print_stack(a);
	printf("disorder: %.2f\n", compute_disorder(a));
	
	printf("operations: %d\n", op_count(0));

	free_stack(a);
	free_stack(b);
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
