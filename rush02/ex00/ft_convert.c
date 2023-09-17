/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkantha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:27:36 by thkantha          #+#    #+#             */
/*   Updated: 2023/06/26 20:38:22 by thkantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
		i += 1;
	return (i);
}

void	write_sep_number(long int val, long int key, int recur)
{
	if (val % key < 10 && val % key != 0 && val < 100)
		write(1, "-", 1);
	else if (val % key > 0 || recur == 1)
		write(1, " ", 1);
}

void	ft_convert(long int val, int size, t_strc *dict, int recur)
{
	int		i;

	if (val == 0)
		write(1, dict[0].value, ft_strlen(dict[0].value));
	while (val != 0)
	{
		i = 0;
		while (dict[i].key - val < 0 && i < size)
			i++;
		if (dict[i].key - val != 0)
			i--;
		while ((dict[i].key > 20 && dict[i].key % 10 != 0))
			i--;
		if (val / dict[i].key >= 1 && val >= 100)
			ft_convert(val / dict[i].key, size, dict, 1);
		write(1, dict[i].value, ft_strlen(dict[i].value));
		write_sep_number(val, dict[i].key, recur);
		val %= dict[i].key;
	}
	if (recur == 0)
		write(1, "\n", 1);
}
/*
int main(void)
{
    struct KeyValue dict[] = {
        {0, "zero"}, //0
        {1, "one"},  //1
        {2, "two"},  //2
        {3, "three"}, //3
        {4, "four"}, //4
        {5, "five"}, //5
        {6, "six"},  //6
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}, // 9
        {10, "ten"}, // 10
        {11, "eleven"}, // 11
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},// 19
        {20, "twenty"}, // 20
        {30, "thirty"}, // 21 <-
        {40, "forty"},
        {50, "fifty"},
        {54, "fifty-four"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"}, // 27 <-
        {100, "hundred"}, // 28 <- 
        {1000, "thousand"}, // 29
        {1000000, "million"}, // 30
        {1000001, "one milion and one"},
        {1000000000, "billion"} // 31
    };
    long int i = 1000000000;
    ft_convert(i, 34, dict, 0);
    return (0);
}
*/
