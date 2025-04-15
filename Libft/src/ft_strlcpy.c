/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:12:00 by llage             #+#    #+#             */
/*   Updated: 2024/10/15 22:03:21 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	n;

	src_length = ft_strlen(src);
	if (size <= 0)
		return (src_length);
	n = src_length;
	if (src_length > size)
		n = size - 1;
	ft_strncpy(dst, src, n);
	if (size > src_length)
		dst[src_length] = '\0';
	else
		dst[size - 1] = '\0';
	return (src_length);
}
