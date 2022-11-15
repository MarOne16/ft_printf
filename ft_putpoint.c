/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:11:54 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/15 16:32:03 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointlen(unsigned long nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb != 0)
	{
		i++;
		nb /= 16;
	}
	return (i + 2);
}

static void	hexaput(unsigned long nbr)
{
	if (nbr >= 16)
		hexaput(nbr / 16);
	ft_printchar("0123456789abcdef"[nbr % 16]);
}

int	ft_putpoint(unsigned long nb)
{
	write(1, "0x", 2);
	hexaput(nb);
	return (pointlen(nb));
}
