/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:49 by llage             #+#    #+#             */
/*   Updated: 2025/04/07 19:42:46 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	print_arg(const int fd, va_list args, char type)
{
	ssize_t	char_count;

	char_count = 0;
	if (type == 'c')
		char_count += print_char(fd, va_arg(args, int));
	else if (type == 's')
		char_count += print_str(fd, va_arg(args, char *));
	else if (type == 'p')
		char_count += print_ptr(fd, va_arg(args, void *));
	else if (type == 'd' | type == 'i')
		char_count += print_nbr(fd, va_arg(args, int));
	else if (type == 'u')
		char_count += print_unbr(fd, va_arg(args, unsigned int));
	else if (type == 'x')
		char_count += print_nbr_hex(fd, va_arg(args, unsigned int), true);
	else if (type == 'X')
		char_count += print_nbr_hex(fd, va_arg(args, unsigned int), false);
	else if (type == '%')
		char_count += print_char(fd, '%');
	return (char_count);
}

static bool	is_valid_specifier(const char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static ssize_t	internal_fprintf(const int fd, const char *str, va_list args)
{
	ssize_t	char_count;
	int		i;

	char_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_specifier(str[i + 1]))
			char_count += print_arg(fd, args, str[++i]);
		else
			char_count += print_char(fd, str[i]);
		i++;
	}
	return (char_count);
}

ssize_t	ft_fprintf(const int fd, const char *str, ...)
{
	ssize_t	char_count;
	va_list	args;

	va_start(args, str);
	char_count = internal_fprintf(fd, str, args);
	va_end(args);
	return (char_count);
}

ssize_t	ft_printf(const char *str, ...)
{
	ssize_t	char_count;
	va_list	args;

	va_start(args, str);
	char_count = internal_fprintf(1, str, args);
	va_end(args);
	return (char_count);
}
