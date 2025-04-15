/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:27:14 by llage             #+#    #+#             */
/*   Updated: 2024/11/15 08:50:29 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_to_line(char **line, const char *buffer, ssize_t *buffer_i)
{
	ssize_t	line_length;
	ssize_t	to_add_length;
	ssize_t	new_line_length;
	char	*new_line;

	line_length = ft_strlen(*line);
	to_add_length = ft_strlen_new_line(buffer + *buffer_i);
	new_line_length = line_length + to_add_length + 1;
	new_line = ft_calloc(new_line_length, sizeof(char));
	if (new_line == NULL)
		return (free_line_return_null(line));
	ft_strlcpy(new_line, *line, line_length + 1);
	ft_strlcpy(new_line + line_length, buffer + *buffer_i, to_add_length + 1);
	*buffer_i += to_add_length;
	free(*line);
	return (new_line);
}

ssize_t	read_into_buffer(const int fd, char *buffer, const char *line)
{
	ssize_t	read_r;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	read_r = read(fd, buffer, BUFFER_SIZE);
	if (read_r < 0 || (read_r == 0 && ft_strlen(line) == 0))
		read_r = -1;
	return (read_r);
}

char	*return_line_reset_i(char *line, ssize_t *buffer_i)
{
	*buffer_i = 0;
	return (line);
}

char	*get_next_line_2(int fd, char *buffer, ssize_t *buffer_i, char *line)
{
	ssize_t	read_r;

	while (1)
	{
		if (*buffer_i == 0)
		{
			read_r = read_into_buffer(fd, buffer, line);
			if (read_r < 0)
				return (free_line_return_null(&line));
			if (read_r == 0)
				return (line);
		}
		line = add_to_line(&line, buffer, buffer_i);
		if (!buffer[*buffer_i] && line != NULL)
		{
			if (buffer[*buffer_i - 1] == '\n')
				return (return_line_reset_i(line, buffer_i));
			*buffer_i = 0;
		}
		else if (line == NULL || line[0] == '\0')
			return (free_line_return_null(&line));
		else
			return (line);
	}
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static ssize_t	buffer_i;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	if (line == NULL)
		return (NULL);
	return (get_next_line_2(fd, buffer, &buffer_i, line));
}
