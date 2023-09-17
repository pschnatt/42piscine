/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:47:55 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/26 15:01:05 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

int	trim(char *str, t_strc *s_dict, int pos)
{
	int	co;

	co = 0;
	s_dict[pos].value = malloc(sizeof(char) * (find_len_str(str) + 2));
	while (*str == ' ')
		str++;
	while (*str)
	{
		s_dict[pos].value[co] = *str;
		co++;
		if (*str == ' ')
			while (*str == ' ')
				str++;
		else if (*str < 32 || *str > 126)
			return (0);
		else
			str++;
	}
	if (*(str - 1) <= 32 || *(str - 1) > 126)
		co--;
	s_dict[pos].value[co] = '\0';
	return (1);
}

int	find_pos(long long int ans)
{
	if (ans >= 0 && ans <= 20)
		return (ans);
	if (ans % 10 != 0)
		return (-1);
	if (ans / 10 >= 3 && ans / 10 <= 9)
		return ((ans / 10) + 18);
	if (ans == 100)
		return (28);
	if (ans == 1000)
		return (29);
	if (ans == 1000000)
		return (30);
	if (ans == 1000000000)
		return (31);
	return (-1);
}

int	pstr(char *str, t_strc *s_dict)
{
	long long int	ans;
	int				i;

	i = 0;
	while (*str)
	{
		if (*str == ':')
		{
			*str = '\0';
			ans = ft_atoi(str - i);
			i = 0;
			if (find_pos(ans) != -1)
			{
				s_dict[find_pos(ans)].key = ans;
				if (!trim(str + 1, s_dict, find_pos(ans)))
					return (0);
				return (1);
			}
			return (0);
		}
		str++;
		i++;
	}
	return (0);
}

int	count_word(int fd, t_strc *s_dict)
{
	char		a[100];
	int			check;
	int			co;
	int			i;
	char		c;

	co = 0;
	check = 0;
	i = -1;
	while (read(fd, &c, 1))
	{
		a[++i] = c;
		if (check == 0 && c == '\n')
		{
			co++;
			a[i] = '\0';
			if (pstr(a, s_dict) == 0 || i == 0)
				co--;
			i = -1;
			check = 1;
		}
		else if (c != '\n')
			check = 0;
	}
	return (co);
}
