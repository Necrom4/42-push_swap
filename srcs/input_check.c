/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:28:58 by dferreir          #+#    #+#             */
/*   Updated: 2023/01/09 14:23:52 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	order_checker(int *stack_a, int len_a)
{
	int	i;
	int	acc;

	i = 0;
	acc = 1;
	while (i < len_a - 1)
	{
		if (stack_a[i] < stack_a[i + 1])
			acc++;
		i++;
	}
	if (acc == len_a)
		return (1);
	else
		return (0);
}

void	errors(char **stack, int len)
{
	int	i;

	if (is_digit(stack, len))
	{
		write (2, "Error\n", 6);
		exit (0);
	}
	i = 0;
	while (i < len)
	{
		if (ft_atoi(stack[i]) < -2147483648 || ft_atoi(stack[i]) > 2147483647)
		{
			write (2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	if (are_dup(stack, len))
	{
		write (2, "Error\n", 6);
		exit (0);
	}
}

void	indexed_checker(char **tmp, int *i, int *smallest)
{
	int	ptr_i;
	int	ptr_s;

	ptr_i = 0;
	ptr_s = 0;
	while (tmp[ptr_i][0] == 'a')
	{
		ptr_i++;
		ptr_s++;
	}
	ptr_i++;
	*i = ptr_i;
	*smallest = ptr_s;
}

int	is_digit(char **stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (stack[i][j])
		{
			if (stack[i][j] == ' ' || stack[i][j] == '-' || stack[i][j] == '+')
				j++;
			else if (!ft_isdigit(stack[i][j]))
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	are_dup(char **stack, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < n)
	{
		while (j < n)
		{
			if (ft_atoi(stack[i]) == ft_atoi(stack[j++]))
				return (1);
		}
		i++;
		j = i + 1;
	}
	return (0);
}
