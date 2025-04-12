/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:23:59 by llage             #+#    #+#             */
/*   Updated: 2024/12/18 22:24:52 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_ptr(const int fd, const void *ptr)
{
	ssize_t	char_count;

	if (ptr == NULL)
		return (print_str(fd, "(nil)"));
	char_count = 0;
	char_count += print_str(fd, "0x");
	char_count += print_nbr_hex(fd, (unsigned long) ptr, true);
	return (char_count);
}

ssize_t	print_nbr_hex(const int fd, unsigned long n, bool lowercase)
{
	char	*hex_map;
	ssize_t	char_count;

	if (lowercase)
		hex_map = "0123456789abcdef";
	else
		hex_map = "0123456789ABCDEF";
	char_count = 0;
	if (n >= 16)
		char_count += print_nbr_hex(fd, n / 16, lowercase);
	char_count += print_char(fd, hex_map[n % 16]);
	return (char_count);
}
