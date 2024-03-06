/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:29:24 by dferreir          #+#    #+#             */
/*   Updated: 2022/12/23 10:29:25 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	rb(int *stack_b, int len_b)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_b[0];
	while (i < len_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = tmp;
	write (1, "rb\n", 3);
}
