/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:10:50 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/20 18:52:11 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** #1. The string from which to create the substring.
** #2. The start index of the substring in the string ’s’.
** #3. The maximum length of the substring.
**
** Allocates (with malloc(3)) and returns a substring
** from the string ’s’.
** The substring begins at index ’start’ and is of
** maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_size;
	size_t	i;

	if (!s)
		return (NULL);
	substr = "";
	s_size = ft_strlen(s);
	i = 0;
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s_size < start)
	{
		substr[0] = '\0';
		return (substr);
	}
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
