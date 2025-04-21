/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:45:17 by llage             #+#    #+#             */
/*   Updated: 2024/10/17 05:50:24 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb > 0 && size > 0 && (total_size / size) != nmemb)
		return (NULL);
	result = malloc(total_size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, total_size);
	return (result);
}
