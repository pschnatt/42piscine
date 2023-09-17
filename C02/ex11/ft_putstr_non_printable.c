/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:49:49 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/16 12:08:29 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	n;
	unsigned char	ch;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < 32 || str[n] > 126)
		{
			ft_putchr('\\');
			ch = str[n];
			ft_putchr("0123456789abcdef"[ch / 16]);
			ft_putchr("0123456789abcdef"[ch % 16]);
		}	
		else
			ft_putchr(str[n]);
		n++;
	}
}
