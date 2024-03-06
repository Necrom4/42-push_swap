/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:29:16 by dferreir          #+#    #+#             */
/*   Updated: 2022/12/23 10:29:18 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ra(int *stack_a, int len_a)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_a[0];
	while (i < len_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = tmp;
	write (1, "ra\n", 3);
}
