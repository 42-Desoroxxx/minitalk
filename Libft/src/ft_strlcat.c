/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:57:18 by llage             #+#    #+#             */
/*   Updated: 2024/10/23 02:58:30 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	result_length;

	dst_length = ft_strlen(dst);
	if (dst_length > size)
		dst_length = size;
	result_length = dst_length + ft_strlen(src);
	if (size > 0 && size > dst_length)
		ft_strlcpy(dst + dst_length, src, size - dst_length);
	return (result_length);
}
