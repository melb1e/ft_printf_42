/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:32:01 by mmarcele          #+#    #+#             */
/*   Updated: 2021/12/05 14:10:23 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int		ft_printf(const char *input, ...);
int		ft_nDigits(int i);

int		ft_print_char(char c, int fd);
int		ft_print_string(char *string, int fd);
int		ft_print_number(int number, int fd);
int		ft_print_hex(unsigned int number, int fd, char *hex);
int		ft_print_pointer(void *pointer, int fd);
int		ft_print_hex_p(unsigned long pointer, int fd, char *hex);
int		ft_unsigned_putnbr(unsigned int number, int fd);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str_arg);

#endif
/*
** !FT_PRINTF_H
*/