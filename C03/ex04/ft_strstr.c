/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:34:32 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/14 15:09:07 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	to_find_len;
	int	j;

	n = 0;
	if (to_find[n] == '\0')
	{
		return (str);
	}
	to_find_len = ft_strlen(to_find);
	while (str[n])
	{
		if (str[n] == to_find[0])
		{	
			j = 0;
			while (str[n + j] == to_find[j] && to_find[j] != '\0')
			{
				j++;
			}			
			if (j == to_find_len)
				return (str + n);
		}
	n++;
	}
	return (0);
}
