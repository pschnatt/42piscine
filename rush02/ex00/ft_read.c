/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:35:56 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/26 22:29:05 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "header.h"

int	find_len_str(char *str)
{
	int	co;

	co = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		co++;
		if (*str == ' ')
			while (*str == ' ')
				str++;
		else
			str++;
	}
	if (*(str - 1) == ' ')
		co--;
	return (co);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

int	checkdict(t_strc *dict)
{
	int	i;
	int	j;

	i = 0;
	while (i < 31)
	{
		j = i + 1;
		while (j < 32)
		{
			if (!ft_strcmp(dict[i].value, dict[j].value))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_strc	*ft_read(char *file_path)
{
	int		fd;
	int		co;
	t_strc	*s_dict;

	s_dict = malloc(sizeof(t_strc) * 32);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		co = count_word(fd, s_dict);
	close(fd);
	if (co != 32)
		return (0);
	if (!checkdict(s_dict))
		return (0);
	return (s_dict);
}
