/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:00:18 by llage             #+#    #+#             */
/*   Updated: 2024/10/17 02:16:54 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_copy;

	s_copy = s;
	while (n--)
	{
		if (*s_copy == (unsigned char) c)
			return ((void *) s_copy);
		s_copy++;
	}
	return (NULL);
}
