/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:14:25 by dferreir          #+#    #+#             */
/*   Updated: 2022/11/28 10:14:46 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sb(int *stack_b)
{
	int	tmp;

	tmp = stack_b[1];
	stack_b[1] = stack_b[0];
	stack_b[0] = tmp;
	write (1, "sb\n", 3);
}
