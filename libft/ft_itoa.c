/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:19:29 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/24 22:05:28 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** #1. the integer to convert.
**
** Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
*/

static size_t	count(long int i)
{
	int	count;

	count = 1;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 9)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long int	nb;

	nb = n;
	i = count(nb);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i--] = 0;
	if (nb == 0)
	{
		str[0] = '0';
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
