/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:54:53 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/15 16:31:22 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(long long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i = 1;
		nb *= -1;
	}
	if (nb == 0)
		i = 1;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static void	ft_putnbr1(int nbr)
{
	int	x;

	x = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		x = 1;
	}
	if (x == 1)
		write(1, "-", 1);
	if (nbr > 9)
		ft_putnbr1(nbr / 10);
	ft_printchar("0123456789"[nbr % 10]);
}

int	ft_putnbr(int nbr)
{
	ft_putnbr1(nbr);
	return (nbrlen(nbr));
}
