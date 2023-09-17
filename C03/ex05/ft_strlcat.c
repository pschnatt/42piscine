/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:31 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/16 14:51:04 by scrattan         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	i;
	unsigned int	og_destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	og_destlen = destlen;
	i = 0;
	if (size == 0 || size <= destlen)
	{
		return (srclen + size);
	}
	while (src[i] != '\0' && i < size - og_destlen - 1)
	{
		dest[destlen] = src[i];
		i++;
		destlen++;
	}
	dest[destlen] = '\0';
	return (og_destlen + srclen);
}

//#include <string.h>
//int	main(void)
//{
//	char	a[20] = "42 Bang";
//	char	b[] = "kok";
//	char	c[20] = "42 Bang";
//	char	d[] = "kok";
//
//	printf("%d",strlcat(a,b,1));
//	printf("%d",ft_strlcat(c,d,1));
//	printf("\nReal : %s",a);
//	printf("\nImper : %s",c);
//}
