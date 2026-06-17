/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:59:08 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/17 17:25:13 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 push_swap $(./tools/ps_gen/ps_gen 5 0.2 1 0 1) | ./checker $(./tools/ps_gen/ps_gen 5 0.2 1 0 1) 
 per leggere input utilizzare get next line con FD = 0 che legge dallo standard input.
 ogni riga letta rappresenta una singola istruzione di push swap.
 mentre argomenti con argc e argv
*/

int main (int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_ps_flags	f;
	float		d;
	int			i;

	if (argc < 2)
		return (0);
	a = new_stack();
	b = new_stack();
	i = assign_flags(&f, argv, argc);
	if (!a || !b || i < 0 || !input_to_stack(&argv[i], a))
		return (free_stack(a), free_stack(b), write(1, "Error\n", 6), 0);
	/* TODO drop unused 'd' (-Werror); the checker computes no disorder */
	/* TODO keep main thin: push work to helpers (var & 25-line caps) */
	/* TODO 1 replay: read_ops(a, b, f) -> stream get_next_line(0) */
	/* TODO   apply each op with bench = 1; free each line as you go */
	/* TODO   unknown op -> free stacks + "Error\n" + stop reading */
	/* TODO 2 verdict: is_sorted(a) && b->size == 0 ? "OK\n" : "KO\n" */
	/* TODO 3 free_stack(a) + free_stack(b) on every exit path */
	return (0);
}
