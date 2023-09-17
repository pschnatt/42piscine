/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:55:40 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/18 16:24:04 by scrattan         ###   ########.fr       */
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

void	writebase(int nbr, char *base, int baselen)
{
	int		i;
	char	buffer[50];

	i = 1;
	if (nbr == -2147483648)
	{
		buffer[i++] = base[2147483648 % baselen];
		nbr /= baselen;
	}
	if (nbr < 0)
	{
		ft_putchr('-');
		nbr *= -1;
	}
	while (nbr >= baselen)
	{
		buffer[i++] = base[nbr % baselen];
		nbr /= baselen;
	}
	buffer[i] = base[nbr % baselen];
	while (i != 0)
	{
		ft_putchr(buffer[i--]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;

	baselen = ft_basecheck(base);
	if (baselen == 0)
		return ;
	writebase(nbr, base, baselen);
}
