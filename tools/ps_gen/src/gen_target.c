/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ps_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:05:40 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/14 18:05:45 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_gen.h"

int	get_size(t_gen *g)
{
	char	*line;

	g->size = 0;
	while (g->size < 1 || g->size > 1000)
	{
		ft_printf("How many numbers? (1 - 1000)\n");
		line = get_next_line(0);
		if (!line)
			return (0);
		g->size = ft_atoi(line);
		free(line);
		if (g->size < 1 || g->size > 1000)
			ft_printf("Invalid size, enter a number between 1 and 1000\n");
	}
	return (1);
}

int	get_disorder(t_gen *g)
{
	char	*line;

	g->dis_target = -1;
	while (g->dis_target < 0.0f || g->dis_target > 1.0f)
	{
		ft_printf("How much disorder? (0.0 - 1.0)\n");
		line = get_next_line(0);
		if (!line)
			return (0);
		g->dis_target = (float)atof(line);
		free(line);
		if (g->dis_target < 0.0f || g->dis_target > 1.0f)
			ft_printf("Invalid, enter a number between 0.0 and 1.0\n");
	}
	return (1);
}

int	get_algorithm(t_gen *g)
{
	char	*line;

	g->level = -1;
	while (g->level == -1)
	{
		ft_printf("Which algorithm?\n(adaptive | simple | medium | complex)\n");
		line = get_next_line(0);
		if (!line)
			return (0);
		if (!ft_strncmp(line, "adaptive\n", 9))
			g->level = 0;
		else if (!ft_strncmp(line, "simple\n", 7))
			g->level = 1;
		else if (!ft_strncmp(line, "medium\n", 7))
			g->level = 2;
		else if (!ft_strncmp(line, "complex\n", 8))
			g->level = 3;
		else
			ft_printf("Invalid: enter adaptive, simple, medium or complex\n");
		free(line);
	}
	return (1);
}

int	get_bench(t_gen *g)
{
	char	*line;

	g->bench = -1;
	while (g->bench == -1)
	{
		ft_printf("Do you need benchmarks? (y / n)\n");
		line = get_next_line(0);
		if (!line)
			return (0);
		if (!ft_strncmp(line, "y\n", 2))
			g->bench = 1;
		else if (!ft_strncmp(line, "n\n", 2))
			g->bench = 0;
		else
			ft_printf("Invalid: enter y or n\n");
		free(line);
	}
	return (1);
}

int	init_targets(t_gen *g)
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

int	gen_rank(t_gen *g)
{
	g->rank = malloc(g->size * sizeof(int));
	if (!g->rank)
		return (0);
	if (g->dis_target < 0.5f)
		fill_ascending(g);
	else
		fill_descending(g);
	calc_disorder(g);
	if (g->dis_now < g->dis_target)
		make_chaos(g);
	else
		make_order(g);
	return (1);
}



