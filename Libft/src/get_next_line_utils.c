/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:30:19 by llage             #+#    #+#             */
/*   Updated: 2024/11/16 08:54:49 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_line_return_null(char **line)
{
	if (*line != NULL)
		free(*line);
	return (NULL);
}

ssize_t	ft_strlen_new_line(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		if (s[length++] == '\n')
			break ;
	return (length);
}
