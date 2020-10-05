/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:39:24 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/02 19:02:44 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*s_helper;
	int				i;

	find = (unsigned char)c;
	s_helper = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (s_helper[i] == find)
		{
			return (s_helper + i);
		}
		i++;
	}
	return (NULL);
}
