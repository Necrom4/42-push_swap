/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:24:08 by dferreir          #+#    #+#             */
/*   Updated: 2023/01/09 15:22:23 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//libft

long	ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);

int		ft_isdigit(int c);

//sorting actions

void	sa(int *stack_a);

void	sb(int *stack_b);

void	ss(int *stack_a, int *stack_b);

void	pa(int *stack_a, int *stack_b, int *len_a, int *len_b);

void	pb(int *stack_b, int *stack_a, int *len_b, int *len_a);

void	ra(int *stack_a, int len_a);

void	rb(int *stack_b, int len_b);

void	rr(int *stack_a, int *stack_b, int len_a, int len_b);

void	rra(int *stack_a, int len_a);

void	rrb(int *stack_b, int len_b);

void	rrr(int *stack_a, int *stack_b, int len_a, int len_b);

//sorting

void	indexer(int *stack_a, int len_a, char **argv, int j);

void	short_sort(int *stack_a, int *stack_b, int *len_a, int *len_b);

void	sort(int *stack_a, int *stack_b, int *len_a, int *len_b);

//input_checkers

int		order_checker(int *stack_a, int len_a);

void	indexed_checker(char **tmp, int *i, int *smallest);

void	errors(char **stack, int len);

int		is_digit(char **stack, int len);

int		are_dup(char **stack, int n);

int		separator(char **stack, int *len);

#endif
