/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:53:33 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/20 20:27:23 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** #1. The string to be trimmed.
** #2. The reference set of characters to trim.
**
** Allocates (with malloc(3)) and returns a copy of
** ’s1’ with the characters specified in ’set’ removed
** from the beginning and the end of the string.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	s1_size;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_size = ft_strlen(s1);
	while (s1_size && ft_strchr(set, s1[s1_size]))
		s1_size--;
	trim = ft_substr((char *)s1, 0, s1_size + 1);
	return (trim);
}
