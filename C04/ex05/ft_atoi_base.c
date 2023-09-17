/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:26:54 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/18 21:30:03 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(char ch)
{
	write(1, &ch, 1);
}

int	ft_basecheck(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == 43 || str[i] == 45)
			|| (str[i] >= 0 && str[i] <= 32)
			|| (str[i] == 127))
			return (0);
		j = 1;
		while (str[j + i] != '\0')
		{
			if (str[i] == str[j + i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	get_digit_value(char digit, char *base, int len_base)
{
	int	i;

	i = 0;
	while (i < len_base)
	{
		if (digit == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_baseatoi(char *str, int result, int len_base, char *base)
{
	int	digit_value;
	int	found;
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str != '\0')
	{
		found = 0;
		digit_value = get_digit_value(*str, base, len_base);
		if (digit_value == -1)
			return (0);
		result = result * len_base + digit_value;
		str++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	baselen;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	baselen = ft_basecheck(base);
	if (baselen == 0)
		return (0);
	result = ft_baseatoi(str, result, baselen, base);
	return (result);
}
