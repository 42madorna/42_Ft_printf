/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:35:13 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/04 20:58:06 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *fmt, ...)
{
	t_printf	pstrc;

	ft_bzero(&pstrc, sizeof(t_printf));
	pstrc.fmt = fmt;
	va_start(pstrc.ap, fmt);
	while (*pstrc.fmt)
	{
		if (*pstrc.fmt != '%')
			pstrc.count += write(1, pstrc.fmt, 1);
		else
		{
			ft_check_flags(&pstrc);
			ft_check_conv(&pstrc);
			continue ;
		}
		++pstrc.fmt;
	}
	va_end(pstrc.ap);
	return (pstrc.count);
}
