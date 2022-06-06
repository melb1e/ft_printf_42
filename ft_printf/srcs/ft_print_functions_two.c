/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:48:01 by mmarcele          #+#    #+#             */
/*   Updated: 2021/12/05 14:10:45 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int number, int fd)
{
	ft_putnbr_fd(number, fd);
	return (ft_nDigits(number));
}

int	ft_print_char(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_print_string(char *string, int fd)
{
	if (string == 0)
		string = "(null)";
	ft_putstr_fd(string, fd);
	return (ft_strlen(string));
}
