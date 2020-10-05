/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:35:39 by madorna-          #+#    #+#             */
/*   Updated: 2020/09/28 20:36:00 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_repeat(char c, int width, int print)
{
	int count;

	count = -1;
	while (++count < width)
		print == 1 ? write(1, &c, 1) : 0;
	return (count);
}
