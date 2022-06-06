/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:48:07 by mmarcele          #+#    #+#             */
/*   Updated: 2021/12/05 14:10:12 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT32_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
	{
		return ;
	}
	while (*s != 0)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

size_t	ft_strlen(const char *str_arg)
{
	size_t	length;

	length = 0;
	while (*str_arg != 0)
	{
		str_arg++;
		length++;
	}
	return (length);
}

int	ft_nDigits(int number)
{
	int	length;

	length = 0;
	if (number <= 0)
		length++;
	while (number != 0)
	{
		number = number / 10;
		length++;
	}
	return (length);
}
