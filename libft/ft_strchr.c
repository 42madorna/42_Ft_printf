/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:47:58 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/21 18:48:38 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *string;

	string = (char *)s;
	while (*string != c)
	{
		if (*string == '\0')
		{
			return (NULL);
		}
		string++;
	}
	return (string);
}
