/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:39:33 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/26 16:48:49 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	signandspace(char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

long long int	number(char *str, int *i, long long int *value)
{
	int	numcount;

	numcount = 0;
	while ((str[*i] >= '0' && str[*i] <= '9'))
	{
		if (*value == -1)
			(*value) = 0;
		(*value) *= 10;
		(*value) += (str[*i] - 48);
		(*i)++;
	}
	return (*value);
}

long long int	ft_atoi(char *str)
{
	long long int	value;
	int				i;

	i = 0;
	value = -1;
	if (signandspace(str, &i) == -1)
		return (-1);
	value = number(str, &i, &value);
	return (value);
}
