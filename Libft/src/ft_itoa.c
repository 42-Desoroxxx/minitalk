/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:55:27 by llage             #+#    #+#             */
/*   Updated: 2024/10/22 11:43:29 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	int_length(int n)
{
	size_t	length;

	length = 1;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	itoa(int n, size_t length, char *result)
{
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if (n == 0)
		result[length] = '0';
	while (n)
	{
		result[length--] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = int_length(n);
	result = ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	itoa(n, length - 1, result);
	return (result);
}
