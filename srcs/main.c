/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:48:09 by dferreir          #+#    #+#             */
/*   Updated: 2023/01/09 15:22:05 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	else_creator(char **argv, char **tmp, int i)
{
	i = 1;
	while (argv[i])
	{
		tmp[i - 1] = argv[i];
		i++;
	}
}

char	**stack_creator(char **argv, int *len)
{
	char	**tmp;
	int		i;

	i = 0;
	if (len[0] == 1)
	{
		while (argv[1][i])
			i++;
		argv[1][i] = '\0';
		tmp = ft_calloc(i + 1, sizeof (char *));
		tmp[0] = argv[1];
		i = separator(tmp, len);
		if (i)
		{
			free(tmp);
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	else
	{
		tmp = ft_calloc(len[0], sizeof (char *));
		else_creator(argv, tmp, i);
	}
	return (tmp);
}

void	weirdo_finder(char **stack, int len)
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
			{
				if (stack[i][j + 1] == ' ' || stack[i][j + 1] == '-' ||
						stack[i][j + 1] == '+' || stack[i][j + 1] == '\0')
				{
					free(stack);
					write(2, "Error\n", 6);
					exit(0);
				}
				j++;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	**tmp;
	int		len_a;
	int		len_b;

	len_a = argc - 1;
	len_b = 0;
	if (argc == 1)
		return (0);
	tmp = stack_creator(argv, &len_a);
	errors(tmp, len_a);
	weirdo_finder(tmp, len_a);
	stack_a = ft_calloc(len_a, sizeof(int));
	stack_b = ft_calloc(len_a, sizeof(int));
	indexer(stack_a, len_a, tmp, 0);
	free(tmp);
	sort(stack_a, stack_b, &len_a, &len_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
