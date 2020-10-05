/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:48:32 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/04 23:03:03 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include "../../libft/libft.h"

void	ft_print_nbr(char *base, t_printf *pstrc, int nbr)
{
	int	nbrf[100];
	int	i;
	int	neg;

	pstrc->base = base;
	i = !pstrc->flags.pre && nbr == 0 && pstrc->flags.dot ? 0 : ft_nb(pstrc,
		nbr, nbrf, 0);
	neg = nbr < 0 ? 1 : 0;
	if ((!pstrc->flags.minus && !pstrc->flags.zero) || (pstrc->flags.zero &&
		pstrc->flags.pre && !pstrc->flags.minus))
	{
		if (pstrc->flags.dot)
			pstrc->count += pstrc->flags.pre <= i && pstrc->flags.pre != 0 &&
				(i != pstrc->flags.pre)
			? ft_repeat(' ', pstrc->flags.width - pstrc->flags.pre - neg - 1, 1)
			: ft_repeat(' ', pstrc->flags.width - pstrc->flags.pre - neg, 1);
		else
			pstrc->count += ft_repeat(' ', pstrc->flags.width - i - neg, 1);
	}
	i = !pstrc->flags.pre && nbr == 0 && pstrc->flags.dot ? 0 : ft_nb(pstrc,
		nbr, nbrf, 1);
	if (pstrc->flags.dot || pstrc->flags.zero)
		pstrc->flags.pre = pstrc->flags.dot ? pstrc->flags.pre
		: pstrc->flags.width;
	ft_print_nbr_cont(pstrc, nbr, i, nbrf);
}

void	ft_print_nbr_cont(t_printf *pstrc, int nbr, int i, int nbrf[100])
{
	pstrc->count += !pstrc->flags.neg ? ft_repeat('0', pstrc->flags.pre - i, 1)
	: 0;
	while (--i >= 0)
		pstrc->count += write(1, &pstrc->base[nbrf[i]], 1);
	i = !pstrc->flags.pre && nbr == 0 && pstrc->flags.dot ? 0
		: ft_nb(pstrc, nbr, nbrf, 0);
	if (pstrc->flags.dot)
		pstrc->flags.pre = pstrc->flags.pre >= i ? pstrc->flags.pre - i : 0;
	if (pstrc->flags.width > i)
		pstrc->flags.width = nbr >= 0 ? pstrc->flags.width - i
		: pstrc->flags.width - i;
	else
		pstrc->flags.width = pstrc->flags.width - i;
	if (pstrc->flags.minus)
		pstrc->count += ft_repeat(' ', pstrc->flags.width -
		pstrc->flags.pre, 1);
	if (pstrc->flags.neg)
		pstrc->count += ft_repeat(' ', pstrc->flags.pre - i, 1);
}

int		ft_nb(t_printf *pstrc, long long int nbr, int nbrf[100], int p)
{
	int i;
	int s;

	i = 0;
	if (check_base(pstrc->base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			pstrc->count += write(1, "-", p);
			p ? --pstrc->flags.width : 0;
		}
		s = ft_strlen(pstrc->base);
		if (nbr == 0)
			nbrf[i++] = 0;
		else
			while (nbr)
			{
				nbrf[i++] = nbr % s;
				nbr = nbr / s;
			}
	}
	return (i);
}
