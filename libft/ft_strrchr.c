/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:02:29 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/06 19:13:30 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (ft_strchr(s, c) == NULL)
	{
		return (NULL);
	}
	while (*s)
	{
		s++;
	}
	while (*s != c)
	{
		s--;
	}
	return ((char*)s);
}
