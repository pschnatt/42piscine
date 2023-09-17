/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:05:34 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/14 17:04:03 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	destlen;

	destlen = ft_strlen(dest);
	while (*src != '\0' && nb != 0)
	{
		dest[destlen] = *src;
		src++;
		destlen++;
		nb--;
	}
	dest[destlen] = '\0';
	return (dest);
}
