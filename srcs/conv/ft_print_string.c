/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:37:46 by madorna-          #+#    #+#             */
/*   Updated: 2020/09/28 20:38:11 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_string(t_printf *pstrc)
{
	char	*string;
	int		len;

	if (!(string = va_arg(pstrc->ap, char *)))
		string = "(null)";
	len = ft_strlen(string);
	if (len > pstrc->flags.pre && pstrc->flags.dot == 1)
		len = pstrc->flags.pre;
	if (len < pstrc->flags.width)
		pstrc->flags.width = pstrc->flags.width - len;
	else
		pstrc->flags.width = 0;
	if (!pstrc->flags.minus)
		pstrc->count += ft_repeat(' ', pstrc->flags.width, 1);
	pstrc->count += write(1, string, len);
	if (pstrc->flags.minus)
		pstrc->count += ft_repeat(' ', pstrc->flags.width, 1);
}
