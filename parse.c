/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anade-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:00:15 by anade-mo          #+#    #+#             */
/*   Updated: 2026/06/11 14:00:28 by anade-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// must be integer, no special chars, no empty strings
int	validate_input(char **arg_nbr)
{
	int	i;
	int	j;
	i = 0;
	while (arg_nbr[i])
	{
		j = 0;
		if (arg_nbr[i][j] == '-' || arg_nbr[i][j] == '+')
			j++;
		if (arg_nbr[i][j] == '\0')
			return (-1);
		while (arg_nbr[i][j])
		{
			if (!ft_isdigit(arg_nbr[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	if (validate_int_limits(arg_nbr) == -1)
		return (-1);
	return (1);
}

int validate_int_limits(char **arg_nbr)
{
	size_t	len;
	char	*ptr;
	int 	i;
	
	i = 0;
	while (arg_nbr[i])
	{
		ptr = arg_nbr[i];
		if (ptr[0] == '-' || ptr[0] == '+')
			ptr++;
		len = ft_strlen(ptr);
		if (len > 10)
			return (-1);
		if (len == 10)
		{
			if (arg_nbr[i][0] == '-' && ft_strncmp(ptr, "2147483648", 10) > 0)
				return (-1);
			if (arg_nbr[i][0] != '-' && ft_strncmp(ptr, "2147483647", 10) > 0)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	*input_to_array(int size, char **arg_nbr)
{
	int	*arr;
	int	i;

	if (validate_input(arg_nbr) == -1)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi(arg_nbr[i]);
		i++;
	}
	if (validate_int_duplicates(arr, size) == -1)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

int	validate_int_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
int	assign_flags(t_flags *f, char **argv, int argc)
{
	int		i;
	f->level = 0;
	f->bench = 0;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			f->level = 0;
		else if (ft_strncmp(argv[i], "--simple", 9) == 0)
			f->level = 1;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			f->level = 2;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			f->level = 3;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0)
			f->bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}
