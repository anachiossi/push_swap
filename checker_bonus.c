/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:34:07 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/17 15:40:41 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TODO core replay + dispatch live here (split to stay <=5 funcs/file) */
/* TODO read_ops(t_stack *a, t_stack *b, t_ps_flags f): */
/* TODO   line = get_next_line(0); loop while line; free(line) each turn */
/* TODO   code = match_op(line) (checker_utils); -1 -> err_exit */
/* TODO   apply_op(code, a, b); keep reading until EOF */
/* TODO apply_op(int code, t_stack *a, t_stack *b): */
/* TODO   switch(code): sa(1, a) / sb(1, b) / pb(1, a, b) / rr(1, a, b)... */
/* TODO   bench = 1 makes the op apply WITHOUT printing (what we want) */
/* TODO   the switch keeps every call type-correct (no uniform signature needed) */