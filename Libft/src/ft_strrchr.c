/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:59:53 by llage             #+#    #+#             */
/*   Updated: 2024/10/16 01:15:57 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*latest_occurrence;

	latest_occurrence = NULL;
	while (1)
	{
		if (*s == (char) c)
			latest_occurrence = (char *) s;
		if (!*s)
			break ;
		s++;
	}
	return (latest_occurrence);
}
