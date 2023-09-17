/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:26:54 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/21 14:28:45 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*intptr;
	int	i;

	i = 0;
	if (max <= min)
	{
		return (0);
	}
	intptr = (int *)malloc(sizeof(int) * (max - min));
	while (max > min)
	{
		intptr[i] = min;
		min++;
		i++;
	}
	return (intptr);
}
