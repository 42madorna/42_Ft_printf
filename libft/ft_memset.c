/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:43:33 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/02 17:45:26 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char	*b_helper;
	size_t	i;

	b_helper = b;
	i = 0;
	while (i < n)
	{
		b_helper[i++] = c;
	}
	return (b);
}
