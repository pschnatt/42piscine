/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:37:08 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/20 11:17:28 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 2;
	while (i > 0)
	{
		j = argc - 2;
		while (j != argc - 2 - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) < 0)
				ft_swap(&argv[j], &argv[j + 1]);
			j--;
		}
		i--;
	}
	while (argc >= 2)
	{
		ft_putstr(argv[argc - 1]);
		write(1, "\n", 1);
		argc--;
	}
	return (1);
}
