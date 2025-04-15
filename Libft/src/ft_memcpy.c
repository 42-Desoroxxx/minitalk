/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:06:24 by llage             #+#    #+#             */
/*   Updated: 2024/10/22 11:59:46 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_copy;
	const unsigned char	*src_copy;

	if (dest == NULL && src == NULL)
		return (dest);
	dest_copy = dest;
	src_copy = src;
	while (n-- > 0)
	{
		*dest_copy = *src_copy;
		dest_copy++;
		src_copy++;
	}
	return (dest);
}
