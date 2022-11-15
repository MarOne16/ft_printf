/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:16 by mqaos             #+#    #+#             */
/*   Updated: 2022/11/15 16:29:17 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putnbr(int nbr);
int		ft_printchar(int c);
int		ft_putnbrun(unsigned int nbr);
int		ft_puthexa(unsigned int nbr);
int		ft_puthexam(unsigned int nbr);
int		ft_putstr(char *str);
int		ft_putpoint(unsigned long nb);
int		ft_formatspf(va_list args, const char format);
int		ft_printf(const char *format, ...);
#endif