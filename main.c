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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	f;
	float	d;
	int		i;

	if (argc < 2)
		return (0);
	a = new_stack();
	b = new_stack();
	i = assign_flags(&f, argv, argc);
	if (!a || !b || i < 0 || !input_to_stack(&argv[i], a))
		return (free_stack(a), free_stack(b), write(1, "Error\n", 6), 0);
	d = disorder(a);
	dispatcher(a, b, f);
	if (f.bench)
		benchmode(d, op_count(-1));
	free_stack(a);
	free_stack(b);
	return (0);
}
