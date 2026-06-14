/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:58:42 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/14 18:58:52 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_gen.h"

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
