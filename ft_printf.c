/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:32:55 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/16 20:32:57 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_formatspf(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putpoint(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbrun(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_puthexa(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_puthexam(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putpercent();
	else
		len += ft_printchar(format);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 0)
			return (i);
		if (str[i] == '%')
		{
			len += ft_formatspf(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
