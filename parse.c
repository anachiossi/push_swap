/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantoni <gsantoni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:00:15 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/12 18:56:18 by gsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		is_valid(char *s)
{
	int		i;
	int		sign;
	int		len;

	if (!s || !*s)
		return (0);
	sign = '+';
	if (*s == '+' || *s == '-')
		sign = *s++;
	len = ft_strlen(s);
	if (!len || len > 10)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	if (len == 10 && sign == '+' && ft_strncmp(s, "2147483647", 10) > 0)
		return (0);
	if (len == 10 && sign == '-' && ft_strncmp(s, "2147483648", 10) > 0)
		return (0);
	return (1);
}

int		input_to_stack(char **arg, t_stack *a)
{
	t_node	*temp;
	t_node	*n;

	if (!a || a->size)
		return (0);
	while (*arg)
	{
		if (!is_valid(*arg))
		{
			free_stack(a);
			return (0);
		}
		n = new_node(ft_atoi(*arg++));
		push(a, n);
		temp = a->top;
		while (a->bottom && a->bottom->value != temp->value)
			temp = temp->next;
		if (!n || temp != a->bottom)
		{
			free_stack(a);
			return (0);
		}
	}
	return (1);
}

int		assign_flags(t_flags *f, char **argv, int argc)
{
	int		i;
	f->level = 0;
	f->bench = 0;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--adaptive", 11))
			f->level = 0;
		else if (!ft_strncmp(argv[i], "--simple", 9))
			f->level = 1;
		else if (!ft_strncmp(argv[i], "--medium", 9))
			f->level = 2;
		else if (!ft_strncmp(argv[i], "--complex", 10))
			f->level = 3;
		else if (!ft_strncmp(argv[i], "--bench", 8))
			f->bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}

void	benchmode(int d, int *n)
{
	printf("[bench] disorder: %d%%\n", d);
	printf("[bench] strategy: %s\n", "...");
	printf("[bench] total ops: %d\n", n[11] - 1);
	printf("[bench] sa: %d\t sb: %d\t ss: %d\t pa: %d\t pb: %d\n", n[0], n[1], n[2], n[3], n[4]);
	printf("[bench] ra: %d\t rb: %d\t rr: %d\t rra: %d\t rrb: %d\t rrr: %d\n", n[5], n[6], n[7], n[8], n[9], n[10]);
}