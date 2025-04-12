/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:32:23 by llage             #+#    #+#             */
/*   Updated: 2024/12/18 22:24:52 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_char(const int fd, const char c)
{
	return (write(fd, &c, 1));
}

ssize_t	print_str(const int fd, const char *str)
{
	size_t	length;

	if (str == NULL)
		return (print_str(fd, "(null)"));
	length = ft_strlen(str);
	return (write(fd, str, length));
}

ssize_t	print_nbr(const int fd, long n)
{
	ssize_t	char_count;

	char_count = 0;
	if (n < 0)
	{
		char_count += print_char(fd, '-');
		n = -n;
	}
	if (n > 9)
		char_count += print_nbr(fd, n / 10);
	char_count += print_char(fd, '0' + (n % 10));
	return (char_count);
}

ssize_t	print_unbr(const int fd, unsigned int n)
{
	ssize_t	char_count;

	char_count = 0;
	if (n > 9)
		char_count += print_nbr(fd, n / 10);
	char_count += print_char(fd, '0' + (n % 10));
	return (char_count);
}
