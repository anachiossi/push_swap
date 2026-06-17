/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:34:07 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/17 19:50:34 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO core function + dispatch live here 

void    read_ops(t_stack a, t_stack b, t_ps_flags f)


// loop: read_ops(a, b, f) -> stream get_next_line(0) 
// line = get_next_line(0); loop while line; free(line) each turn 
// cmp_op(line) (checker_utils); -1 -> error free 
// apply each op with bench = 1; free each line as you go + stop reading 


void    apply_op(int code, t_stack *a, t_stack *b)

// keep reading until EOF
// switch(code): sa(1, a) / sb(1, b) / pb(1, a, b) / rr(1, a, b) ...
// bench = 1 makes the op apply WITHOUT printing ? 
