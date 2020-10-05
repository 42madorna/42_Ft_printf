/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:39:48 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/14 18:14:47 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_helper;
	unsigned char		*dest_helper;

	src_helper = (unsigned char *)src;
	dest_helper = (unsigned char *)dest;
	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	if (src_helper < dest_helper)
	{
		while (++i <= n)
			dest_helper[n - i] = (char)src_helper[n - i];
	}
	else
		while (n-- > 0)
			*(dest_helper++) = *(src_helper++);
	return (dest);
}
