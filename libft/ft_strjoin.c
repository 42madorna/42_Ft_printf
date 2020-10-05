/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:05:28 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/20 19:54:12 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** #1. The prefix string.
** #2. The suffix string.
**
** Allocates (with malloc(3)) and returns a new
** string, which is the result of the concatenation
** of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	size_t	h;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	i = 0;
	h = -1;
	if (!(str = malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[++h] != '\0')
		str[i + h] = s2[h];
	str[i + h] = '\0';
	return (str);
}
