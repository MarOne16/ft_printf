/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:41:01 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/15 16:30:21 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexalen(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = 1;
	while (nbr != 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static void	hexaput(unsigned int nbr)
{
	if (nbr >= 16)
		hexaput(nbr / 16);
	ft_printchar("0123456789abcdef"[nbr % 16]);
}

int	ft_puthexa(unsigned int nbr)
{
	hexaput(nbr);
	return (hexalen(nbr));
}
