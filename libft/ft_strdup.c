/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:37:15 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/14 19:04:27 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	void	*mal;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(mal = malloc(i + 1)))
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		((char *)mal)[i] = s1[i];
		i++;
	}
	((char *)mal)[i] = '\0';
	return (void *)mal;
}
