/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:45:55 by gsantoni          #+#    #+#             */
/*   Updated: 2026/06/13 10:19:10 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	f;
	float		d;

	if (argc < 2)
		return (0);
	a = new_stack();
	b = new_stack();
	if (!input_to_stack(&argv[assign_flags(&f, argv, argc)], a) || !b)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	/*float d = disorder(a);
	printf("before: ");
	print_stack(a);
	printf("disorder: %.2f%\n", d);*/
	
	d = disorder(a);
	dispatcher(a, b, f);
	if (f.bench)
		benchmode(d, op_count(-1));

	/*printf("after:  ");
	print_stack(a);
	printf("disorder: %.2f%\n", disorder(a));

	printf("operations: %d\n", op_count(0));*/

	free_stack(a);
	free_stack(b);
	return (0);
}
