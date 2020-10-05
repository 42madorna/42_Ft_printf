/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:23:59 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/04 20:11:40 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_check_flags(t_printf *pstrc)
{
	ft_bzero(&pstrc->flags, sizeof(pstrc->flags));
	while (*++pstrc->fmt)
	{
		if (*pstrc->fmt == '0')
			pstrc->flags.zero = (pstrc->flags.dot) ? 0 : 1;
		else if (ft_isdigit(*pstrc->fmt))
			ft_check_size(pstrc);
		else if (*pstrc->fmt == '-')
			pstrc->flags.minus = 1;
		else if (*pstrc->fmt == '.')
			pstrc->flags.dot = 1;
		else if (*pstrc->fmt == '*')
			ft_check_asterisk(pstrc);
		else if (*pstrc->fmt == '#')
			pstrc->flags.hashtag = 1;
		else if (*pstrc->fmt == '+')
			pstrc->flags.plus = 1;
		else if (*pstrc->fmt == ' ')
			pstrc->flags.space = 1;
		else
			break ;
	}
}

void	ft_check_size(t_printf *pstrc)
{
	while (ft_isdigit(*pstrc->fmt))
	{
		if (pstrc->flags.dot)
			pstrc->flags.pre = pstrc->flags.pre * 10 + *pstrc->fmt - '0';
		else
			pstrc->flags.width = pstrc->flags.width * 10 + *pstrc->fmt - '0';
		++pstrc->fmt;
	}
	--pstrc->fmt;
}

void	ft_check_asterisk(t_printf *pstrc)
{
	if (pstrc->flags.dot)
	{
		pstrc->flags.pre = va_arg(pstrc->ap, int);
		if (pstrc->flags.pre < 0)
		{
			pstrc->flags.pre = 0;
			pstrc->flags.dot = 0;
		}
	}
	else
	{
		pstrc->flags.width = va_arg(pstrc->ap, int);
		if (pstrc->flags.width < 0)
		{
			pstrc->flags.width *= -1;
			pstrc->flags.neg = 1;
			pstrc->flags.minus = 1;
		}
	}
}
