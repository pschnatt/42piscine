/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:39:16 by scrattan          #+#    #+#             */
/*   Updated: 2023/06/20 17:16:03 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	og_nb;

	if (power < 0 || (nb == 0 && power != 0))
		return (0);
	if (power == 0)
		return (1);
	else
	{
		og_nb = nb;
		while (--power)
		{
			nb *= og_nb;
		}
		return (nb);
	}
}
