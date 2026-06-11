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
#include <stdlib.h>
// must be integer, no special chars, no empty strings
int	validate_input(char **argv)
{
	int	i;
	int	j;
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (-1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	if (validate_int_limits(argv) == -1)
		return (-1);
	return (1);
}

int validate_int_limits(char **argv)
{
	size_t	len;
	char	*ptr;
	int 	i;
	
	i = 1;
	while (argv[i])
	{
		ptr = argv[i];
		if (ptr[0] == '-' || ptr[0] == '+')
			ptr++;
		len = ft_strlen(ptr);
		if (len > 10)
			return (-1);
		if (len == 10)
		{
			if (argv[i][0] == '-' && ft_strncmp(ptr, "2147483648", 10) > 0)
				return (-1);
			if (argv[i][0] != '-' && ft_strncmp(ptr, "2147483647", 10) > 0)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	*input_to_array(int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (validate_int_duplicates(arr, argc - 1) == -1)
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
