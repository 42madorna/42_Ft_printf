/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:21:15 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/24 16:43:07 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*mal;
	size_t	i;
	size_t	total;

	i = 0;
	total = count * size;
	if (!(mal = malloc(total)))
	{
		return (NULL);
	}
	while (total--)
	{
		((char *)mal)[i] = 0;
		i++;
	}
	return (void*)mal;
}
