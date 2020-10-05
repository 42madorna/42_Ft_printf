/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:37:56 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/02 17:42:11 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src_helper;
	unsigned char		*dest_helper;

	dest_helper = (unsigned char*)dest;
	src_helper = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest_helper[i] = src_helper[i];
		if (dest_helper[i] == (unsigned char)c)
		{
			return ((void*)(dest + i + 1));
		}
		i++;
	}
	return (NULL);
}
