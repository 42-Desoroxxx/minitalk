/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:10:04 by llage             #+#    #+#             */
/*   Updated: 2024/10/23 02:32:40 by llage            ###   ########.fr       */
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

static int	count_words(char const *s, const char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c || !count)
		{
			while (*s == c)
				s++;
			if (!*s)
				return (count);
			while (*s && *s != c)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static void	*free_char_array(char **array, int size)
{
	while (size--)
		free(array[size]);
	free(array);
	return (NULL);
}

static char	**split(char const *s, char const c, char **result, int count)
{
	size_t	part_length;
	char	*part;

	while (*s)
	{
		if (*s == c || !count)
		{
			while (*s == c)
				s++;
			if (!*s)
				return (result);
			part_length = 0;
			while (s[part_length] && s[part_length] != c)
				part_length++;
			part = ft_strndup(s, part_length);
			if (part == NULL)
				return (free_char_array(result, count));
			result[count++] = part;
			s += part_length;
		}
		else
			s++;
	}
	result[count] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	result = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	count = 0;
	result = split(s, c, result, count);
	return (result);
}
