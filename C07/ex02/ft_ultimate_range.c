/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:55:18 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/23 15:51:17 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*intptr;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	intptr = (int *)malloc(sizeof(int) * (max - min));
	if (intptr == NULL)
		return (-1);
	while (min < max)
	{
		intptr[i] = min;
		min++;
		i++;
	}
	*range = intptr;
	return (i);
}
