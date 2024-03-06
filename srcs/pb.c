/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:29:07 by dferreir          #+#    #+#             */
/*   Updated: 2022/12/23 10:29:08 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	pb(int *stack_b, int *stack_a, int *len_b, int *len_a)
{
	int	i;

	i = len_b[0];
	if (!stack_a)
		return ;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	while (i < len_a[0] - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	len_b[0]++;
	len_a[0]--;
	write (1, "pb\n", 3);
}
