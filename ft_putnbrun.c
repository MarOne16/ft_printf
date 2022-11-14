/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:24:11 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/14 19:17:21 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_putnbrun01(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbrun(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	ft_putnbrun(unsigned int nbr)
{
	ft_putnbrun01(nbr);
	return (nbrlen(nbr));
}
