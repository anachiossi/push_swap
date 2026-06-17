/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <anade-mo <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:00:15 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/17 12:11:14 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *s)
{
	int	i;
	int	sign;
	int	len;

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

int	input_to_stack(char **arg, t_stack *a)
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
		push_bottom(a, n);
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

void	assign_ranks(t_stack *a)
{
	int		r;
	t_node	*n;
	t_node	*t;

	n = a->top;
	while (n)
	{
		r = 0;
		t = a->top;
		while (t)
		{
			r += (n->value > t->value);
			t = t->next;
		}
		n->rank = r;
		n = n->next;
	}
}

int	assign_flags(t_ps_flags *f, char **argv, int argc)
{
	int	i;

	f->level = -1;
	f->bench = 0;
	i = 1;
	while (i < argc && !is_valid(argv[i]))
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			f->bench = 1;
		else if (!ft_strncmp(argv[i], "--adaptive", 11) && f->level == -1)
			f->level = 0;
		else if (!ft_strncmp(argv[i], "--simple", 9) && f->level == -1)
			f->level = 1;
		else if (!ft_strncmp(argv[i], "--medium", 9) && f->level == -1)
			f->level = 2;
		else if (!ft_strncmp(argv[i], "--complex", 10) && f->level == -1)
			f->level = 3;
		else
			return (-1);
		i++;
	}
	if (f->level == -1)
		f->level = 0;
	return (i);
}

void	benchmode(float d, int *n, int level)
{
	char	*s[4];

	s[0] = "adaptive sort";
	s[1] = "selection / O(n²)";
	s[2] = "chunk / O(n√n)";
	s[3] = "radix / O(n log n)";
	ft_printf("[bench] disorder: %.2f%%\n", d * 100);
	ft_printf("[bench] strategy: %s\n", s[level]);
	ft_printf("[bench] total ops: %d\n", n[11]);
	ft_printf("[bench] sa: %d\tsb: %d\tss: %d\tpa: %d\tpb: %d\n", n[0], n[1],
		n[2], n[3], n[4]);
	ft_printf("[bench] ra: %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr: %d\n",
		n[5], n[6], n[7], n[8], n[9], n[10]);
}
