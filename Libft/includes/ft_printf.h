/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:55:03 by llage             #+#    #+#             */
/*   Updated: 2024/12/18 20:52:41 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <libft.h>

ssize_t	ft_fprintf(int fd, const char *str, ...);
ssize_t	ft_printf(const char *str, ...);

ssize_t	print_nbr_hex(int fd, unsigned long n, bool lowercase);
ssize_t	print_str(int fd, const char *str);
ssize_t	print_ptr(int fd, const void *ptr);
ssize_t	print_unbr(int fd, unsigned int n);
ssize_t	print_char(int fd, char c);
ssize_t	print_nbr(int fd, long n);

#endif
