/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:01:26 by llage             #+#    #+#             */
/*   Updated: 2024/10/23 04:05:17 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static short	is_in_set(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	end;
	char	*result;

	length = ft_strlen(s1);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = length - 1;
	while (s1[end] && is_in_set(s1[end], set))
		end--;
	result = ft_substr(s1, start, (end - start) + 1);
	return (result);
}
