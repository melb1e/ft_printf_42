/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:48:04 by mmarcele          #+#    #+#             */
/*   Updated: 2021/12/05 14:10:43 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(char input, va_list ap, int fd)
{
	if (input == '%')
		return (ft_print_char('%', fd));
	else if (input == 'c')
		return (ft_print_char(va_arg(ap, int), fd));
	else if (input == 's')
		return (ft_print_string(va_arg(ap, char *), fd));
	else if (input == 'd' || input == 'i')
		return (ft_print_number(va_arg(ap, int), fd));
	else if (input == 'x')
		return (ft_print_hex(va_arg(ap, int), fd, HEX_LOWER));
	else if (input == 'X')
		return (ft_print_hex(va_arg(ap, int), fd, HEX_UPPER));
	else if (input == 'u')
		return (ft_unsigned_putnbr(va_arg(ap, unsigned int), fd));
	else if (input == 'p')
		return (ft_print_pointer(va_arg(ap, void *), fd));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	i;
	int		length;

	i = 0;
	length = 0;
	va_start(ap, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			length += ft_parse(input[i + 1], ap, 1);
			i++;
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			length++;
		}
		i++;
	}
	va_end(ap);
	return (length);
}
