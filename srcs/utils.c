/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:55:28 by dferreir          #+#    #+#             */
/*   Updated: 2023/01/09 15:20:09 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	separator(char **stack, int *len)
{
	char	*ptr;
	int		x;
	int		i;

	ptr = stack[0];
	x = 1;
	i = 0;
	if (*ptr == ' ')
		return (1);
	while (*ptr)
	{
		if (*ptr == ' ')
		{
			if (ptr[x] == ' ' || !ptr[x])
				return (1);
			*ptr = '\0';
			i++;
			ptr++;
			stack[i] = ptr;
		}
		else
			ptr++;
	}
	len[0] = i + 1;
	return (0);
}

long	ft_atoi(const char *str)
{
	long	final;
	long	i;
	long	sign;

	final = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		final *= 10;
		final += str[i] - '0';
		++i;
	}
	return (final * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(unsigned char *)(b + i++) = (unsigned char)c;
	return (b);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
