/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:48:02 by llage             #+#    #+#             */
/*   Updated: 2025/04/12 10:48:02 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <s_memory.h>
#include <ft_printf.h>

void	*s_alloc(size_t size, size_t num)
{
	void	*result;

	result = ft_calloc(num, size);
	if (result == NULL)
	{
		ft_fprintf(STDERR_FILENO, "FATAL: Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	return (result);
}

void	s_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
