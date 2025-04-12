/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 07:14:47 by llage             #+#    #+#             */
/*   Updated: 2024/10/23 04:06:16 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	length;
	char	*result;
	int		i;

	length = ft_strlen(s);
	if (length > n)
		length = n;
	result = ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] && n--)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*sub_start;
	size_t		sub_len;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	sub_start = s + start;
	sub_len = ft_strlen(sub_start);
	if (sub_len > len)
		sub_len = len;
	return (ft_strndup(sub_start, sub_len));
}
