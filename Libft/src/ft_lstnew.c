/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:11:41 by llage             #+#    #+#             */
/*   Updated: 2024/10/22 11:52:48 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = ft_calloc(1, sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->content = content;
	return (result);
}
