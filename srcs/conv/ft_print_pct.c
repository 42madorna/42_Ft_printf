/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:26:59 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/04 23:24:19 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_pct(t_printf *pstrc, char c)
{
	if (!pstrc->flags.minus && !pstrc->flags.zero)
		pstrc->count += ft_repeat(' ', pstrc->flags.width - 1, 1);
	else if (pstrc->flags.zero && !pstrc->flags.minus)
		pstrc->count += ft_repeat('0', pstrc->flags.width - 1, 1);
	pstrc->count += write(1, &c, 1);
	if (pstrc->flags.minus)
		pstrc->count += ft_repeat(' ', pstrc->flags.width - 1, 1);
}
