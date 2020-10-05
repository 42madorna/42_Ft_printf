/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:38:50 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/14 18:13:32 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		((char *)dest)[i] = ((const char*)src)[i];
		i++;
	}
	return (dest);
}
