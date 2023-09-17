/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:49:51 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/23 16:04:20 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	ft_alloc_str(char *str, char *ptr, int *ptrindex)
{
	while (*str)
	{
		ptr[*ptrindex] = *str;
		str++;
		(*ptrindex)++;
	}
}

int	ft_strs_len(char **strs, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size)
	{
		j = 0;
		while (strs[size - 1][j])
		{
			i++;
			j++;
		}
		size--;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		ptrindex;
	int		i;
	int		slen;

	ptrindex = 0;
	slen = ft_strs_len(strs, size) + 1;
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (slen + (ft_strlen(sep) * (size - 1))));
	while (size)
	{
		ft_alloc_str(strs[i], ptr, &ptrindex);
		if (size - 1)
			ft_alloc_str(sep, ptr, &ptrindex);
		i++;
		size--;
	}
	ptr[ptrindex] = '\0';
	return (ptr);
}
