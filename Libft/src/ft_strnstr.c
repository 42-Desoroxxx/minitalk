/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:47:56 by llage             #+#    #+#             */
/*   Updated: 2024/10/18 23:27:36 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	find(const char *str, const char *to_find, size_t len)
{
	while (len-- && (*str && *to_find) && *str == *to_find)
	{
		str++;
		to_find++;
	}
	return (!*to_find);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *) big);
	while (len && *big)
	{
		if (find(big, little, len--))
			return ((char *) big);
		big++;
	}
	return (NULL);
}
