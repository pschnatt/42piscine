/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:12:49 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/13 12:17:41 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	int	destlen;

	destlen = ft_strlen(dest);
	while (*src != '\0')
	{
		dest[destlen] = *src;
		src++;
		destlen++;
	}
	dest[destlen] = '\0';
	return (dest);
}
