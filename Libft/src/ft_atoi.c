/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:33:55 by llage             #+#    #+#             */
/*   Updated: 2024/10/20 09:55:33 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*skip_whitespace(const char *str)
{
	while ((*str >= '\t' && *str <= '\r' ) || *str == ' ')
		str++;
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	nptr = skip_whitespace(nptr);
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	return (result * sign);
}
