/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:05:52 by llage             #+#    #+#             */
/*   Updated: 2024/10/23 02:16:27 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_copy;
	const unsigned char	*src_copy;

	if (dest == NULL && src == NULL)
		return (dest);
	dest_copy = dest;
	src_copy = src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dest_copy += n - 1;
		src_copy += n - 1;
		while (n-- > 0)
			*dest_copy-- = *src_copy--;
	}
	return (dest);
}
