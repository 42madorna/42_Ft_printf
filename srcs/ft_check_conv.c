/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:45:18 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/01 18:33:59 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_check_conv(t_printf *pstrc)
{
	if (*pstrc->fmt == 'd' || *pstrc->fmt == 'i')
		ft_print_nbr("0123456789", pstrc,
		va_arg(*(&pstrc->ap), int));
	else if (*pstrc->fmt == 'u')
		ft_print_u("0123456789", pstrc,
		(unsigned int)va_arg(*(&pstrc->ap), unsigned int));
	else if (*pstrc->fmt == 'c')
		ft_print_char(pstrc);
	else if (*pstrc->fmt == 's')
		ft_print_string(pstrc);
	else if (*pstrc->fmt == '%')
		ft_print_pct(pstrc, '%');
	else if (*pstrc->fmt == 'x')
		ft_print_u("0123456789abcdef", pstrc,
		(unsigned int)va_arg(*(&pstrc->ap), unsigned int));
	else if (*pstrc->fmt == 'X')
		ft_print_u("0123456789ABCDEF", pstrc,
		(unsigned int)va_arg(*(&pstrc->ap), unsigned int));
	else if (*pstrc->fmt == 'p')
		ft_print_p(pstrc);
	else if (*pstrc->fmt == 'o')
		ft_print_u("01234567", pstrc, va_arg(*(&pstrc->ap), unsigned int));
	else
		return ;
	++pstrc->fmt;
}
