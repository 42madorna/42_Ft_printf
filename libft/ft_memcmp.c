/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:06:20 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/02 19:59:45 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_helper;
	const unsigned char	*s2_helper;

	if (s1 == s2 || n == 0)
	{
		return (0);
	}
	s1_helper = (const unsigned char *)s1;
	s2_helper = (const unsigned char *)s2;
	while (n--)
	{
		if (*s1_helper != *s2_helper)
		{
			return (*s1_helper - *s2_helper);
		}
		s1_helper++;
		s2_helper++;
	}
	return (0);
}
