/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:47:57 by mmarcele          #+#    #+#             */
/*   Updated: 2021/12/05 14:10:46 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int number, int fd, char *hex)
{
	int	length;

	if (number < 16)
	{
		ft_putchar_fd(hex[number], fd);
		return (1);
	}
	length = ft_print_hex(number / 16, fd, hex);
	ft_print_hex(number % 16, fd, hex);
	return (length + 1);
}

int	ft_print_hex_p(unsigned long int c, int fd, char *hex)
{
	int		length;

	if (c < 16)
	{
		ft_putchar_fd(hex[c], fd);
		return (1);
	}
	length = ft_print_hex_p(c / 16, fd, hex);
	ft_print_hex_p(c % 16, fd, hex);
	return (length + 1);
}

int	ft_print_pointer(void *pointer, int fd)
{
	ft_putstr_fd("0x", fd);
	return (2 + ft_print_hex_p((unsigned long int)pointer, fd, HEX_LOWER));
}

int	ft_unsigned_putnbr(unsigned int number, int fd)
{
	int		length;

	if (number < 10)
	{
		ft_putchar_fd(number + '0', fd);
		return (1);
	}
	else
	{
		length = ft_unsigned_putnbr(number / 10, fd);
		ft_unsigned_putnbr(number % 10, fd);
	}
	return (length + 1);
}
