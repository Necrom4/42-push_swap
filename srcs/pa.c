/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:38:31 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/29 14:52:00 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	pa(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	i;

	i = len_a[0];
	if (!stack_b)
		return ;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	while (i < len_b[0] - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	len_a[0]++;
	len_b[0]--;
	write (1, "pa\n", 3);
}
