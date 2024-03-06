/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:27:58 by dferreir          #+#    #+#             */
/*   Updated: 2023/01/09 15:02:33 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	indexer(int *stack_a, int len_a, char **tmp, int j)
{
	int	i;
	int	smallest;

	while (j < len_a - 1)
	{
		indexed_checker(tmp, &i, &smallest);
		if (tmp[smallest][0] != 'a')
		{
			while (i < len_a)
			{
				if (tmp[i][0] != 'a' &&
					ft_atoi(tmp[i]) < ft_atoi(tmp[smallest]))
					smallest = i;
				i++;
			}
			stack_a[smallest] = j;
			tmp[smallest][0] = 'a';
		}
		j++;
	}
	i = 0;
	while (tmp[i][0] == 'a')
		i++;
	stack_a[i] = j;
}

int	get_max_len(int *stack_a, int len_a)
{
	int	max;
	int	i;
	int	tmp;

	i = 1;
	max = stack_a[0];
	while (i < len_a)
	{
		if (stack_a[i] > max)
			max = stack_a[i];
		i++;
	}
	tmp = max;
	i = 0;
	while (tmp)
	{
		i++;
		tmp >>= 1;
	}
	return (i);
}

void	short_sort_len_3(int *stack_a, int *len_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2])
	{
		if (stack_a[1] > stack_a[2])
		{
			ra(stack_a, len_a[0]);
			sa(stack_a);
		}
		else
			ra(stack_a, len_a[0]);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		sa(stack_a);
	else if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		rra(stack_a, *len_a);
	else
	{
		rra(stack_a, *len_a);
		sa(stack_a);
	}
}

void	short_sort(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	while ((!order_checker(stack_a, *len_a) && !len_b[0])
		|| (!order_checker(stack_a, *len_a) && len_b[0])
		|| (order_checker(stack_a, *len_a) && len_b[0]))
	{
		if (len_a[0] == 2 && !order_checker(stack_a, *len_a))
			sa(stack_a);
		else if (len_a[0] == 3 && !order_checker(stack_a, *len_a))
			short_sort_len_3(stack_a, len_a);
		else if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[len_a[0] - 1]
			&& order_checker(stack_a, *len_a))
			pa(stack_a, stack_b, len_a, len_b);
		else if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[len_a[0] - 1]
			&& !order_checker(stack_a, *len_a))
			pb(stack_b, stack_a, len_b, len_a);
		else if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[len_a[0] - 1])
		{
			sa(stack_a);
			rra(stack_a, *len_a);
		}
		else if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[len_a[0] - 1])
			sa(stack_a);
		else if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[len_a[0] - 1])
			rra(stack_a, *len_a);
	}
}

void	sort(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	max_dig_len;
	int	max_len;
	int	i;
	int	j;

	max_dig_len = get_max_len(stack_a, *len_a);
	max_len = *len_a;
	j = 0;
	if (len_a[0] <= 15)
		short_sort(stack_a, stack_b, len_a, len_b);
	while (j < max_dig_len && !order_checker(stack_a, *len_a))
	{
		i = 0;
		while (i++ < max_len)
		{
			if ((stack_a[0] >> j & 1) == 1)
				ra(stack_a, len_a[0]);
			else
				pb(stack_b, stack_a, len_b, len_a);
		}
		while (len_b[0])
			pa(stack_a, stack_b, len_a, len_b);
		j++;
	}
}
