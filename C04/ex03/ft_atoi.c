/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:14:43 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/16 14:31:04 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += *str - 48;
		str++;
	}
	return (sign * value);
}
