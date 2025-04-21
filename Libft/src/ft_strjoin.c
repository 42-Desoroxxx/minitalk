/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:50:37 by llage             #+#    #+#             */
/*   Updated: 2024/10/17 11:53:58 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*result;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	result = ft_calloc(sizeof(char), s1_length + s2_length + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, s1_length + 1);
	ft_strlcpy(result + s1_length, s2, s2_length + 1);
	return (result);
}
