/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:58:42 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/14 22:59:36 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_gen.h"

static int	init_targets(t_gen *g)
{
	if (!get_size(g))
		return (0);
	if (!get_disorder(g))
		return (0);
	if (!get_algorithm(g))
		return (0);
	if (!get_bench(g))
		return (0);
	return (1);
}

int	main(void)
{
	t_gen	g;

	srand(time(NULL) ^ (unsigned int)getpid());
	ft_printf("Push Swap input generator\n");
	ft_printf("Let's set the parameters:\n");
	if (!init_targets(&g))
		return (1);
	if (!gen_rank(&g))
		return (1);
	if (!gen_value(&g))
		return (free(g.rank), 1);
	calc_disorder(&g);
	print_benchmark(&g);
	print_input(&g);
	free(g.rank);
	free(g.value);
	return (0);
}
