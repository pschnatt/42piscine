/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:03:35 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/26 16:31:11 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	check_error(char *str)
{
	while (*str == ' ' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
		str++;
	while (*str == ' ')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

char	*checkinput(int argc, char **argv)
{
	int		i;
	char	*str;
	char	c;

	i = 0;
	if (argc == 1)
	{
		str = malloc(sizeof(char) * 100);
		write(1, "Please put number : ", 21);
		read(0, &c, 1);
		while (c && c != '\n')
		{
			str[i] = c;
			i++;
			read(0, &c, 1);
		}
		str[i] = '\0';
		return (str);
	}
	if (argc == 2)
		return (argv[1]);
	if (argc == 3)
		return (argv[2]);
	return ("E");
}

void	freedict(t_strc *dict, int argc, char *numb)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		free(dict[i].value);
		i++;
	}
	free(dict);
	if (argc == 1)
		free(numb);
}

int	main(int argc, char **argv)
{
	char			*str;
	t_strc			*dict;
	long long int	ans;
	char			*numb;

	str = (char *)"numbers.dict";
	numb = checkinput(argc, argv);
	if (*numb == 'E' || ft_atoi(numb) > 4294967295 || ft_atoi(numb) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
		str = argv[1];
	dict = ft_read(str);
	if (dict == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	ans = ft_atoi(numb);
	ft_convert(ans, 32, dict, 0);
	freedict(dict, argc, numb);
	return (0);
}
