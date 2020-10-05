/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:31:57 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/22 16:47:42 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	i;
	size_t	h;

	i = 0;
	h = 0;
	if (find[0] == 0)
		return ((char *)src);
	while (src[i] && i < len)
	{
		h = 0;
		if (src[i] == find[h])
		{
			while (i + h < len && src[i + h] == find[h])
			{
				h++;
				if (!find[h])
				{
					return ((char *)&src[i]);
				}
			}
		}
		i++;
	}
	return (0);
}
