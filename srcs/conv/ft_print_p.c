/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:52:18 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/04 23:32:57 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_p(t_printf *pstrc, unsigned long long nbr, int nbrf[100], int p)
{
	int i;
	int s;

	i = 0;
	s = p;
	s = ft_strlen(pstrc->base);
	if (nbr == 0)
		nbrf[i++] = 0;
	else
		while (nbr)
		{
			nbrf[i++] = nbr % s;
			nbr = nbr / s;
		}
	return (i);
}

void	ft_print_po(char *base, t_printf *pstrc, unsigned long long nbr)
{
	int	nbrf[100];
	int	i;
	int neg;

	pstrc->base = base;
	i = !pstrc->flags.pre && nbr == 0 && pstrc->flags.dot ? 0 : ft_p(pstrc,
		nbr, nbrf, 0);
	neg = 0;
	if ((!pstrc->flags.minus && !pstrc->flags.zero) || (pstrc->flags.zero &&
		pstrc->flags.pre && !pstrc->flags.minus))
	{
		if (pstrc->flags.dot)
			pstrc->count += pstrc->flags.pre <= i && pstrc->flags.pre != 0 ?
			ft_repeat(' ', pstrc->flags.width - pstrc->flags.pre - neg - 1 -
			ft_print_hashtag(pstrc, nbr, 0), 1)
			: ft_repeat(' ', pstrc->flags.width - pstrc->flags.pre - neg -
			ft_print_hashtag(pstrc, nbr, 0), 1);
		else
			pstrc->count += ft_repeat(' ', pstrc->flags.width - i - neg -
			ft_print_hashtag(pstrc, nbr, 0), 1);
	}
	ft_print_hashtag(pstrc, nbr, 2);
	i = !pstrc->flags.pre && nbr == 0 && pstrc->flags.dot ? 0 : ft_p(pstrc,
		nbr, nbrf, 1);
	ft_print_po_cont(pstrc, nbr, i, nbrf);
}

void	ft_print_po_cont(t_printf *pstrc, unsigned long long nbr, int i,
		int nbrf[100])
{
	if (pstrc->flags.dot || pstrc->flags.zero)
		pstrc->flags.pre = pstrc->flags.dot ? pstrc->flags.pre
		: pstrc->flags.width;
	if (pstrc->flags.dot && pstrc->flags.hashtag)
		if (nbr != 0)
			if (!pstrc->flags.width)
				pstrc->count += pstrc->flags.pre <= i
				? ft_repeat('0', pstrc->flags.pre - i, 1)
				: ft_repeat('0', pstrc->flags.pre -
				ft_print_hashtag(pstrc, nbr, 0), 1);
			else
				pstrc->count += ft_repeat('0', pstrc->flags.pre -
				ft_print_hashtag(pstrc, nbr, 0), 1);
		else
			pstrc->count += ft_repeat('0', pstrc->flags.pre - 1, 1);
	else
		pstrc->count += ft_repeat('0', pstrc->flags.pre - i -
		ft_print_hashtag(pstrc, nbr, 0), 1);
	while (--i >= 0 && (unsigned int)nbr != 4294967295u)
		pstrc->count += write(1, &pstrc->base[nbrf[i]], 1);
	ft_print_po_cont_cont(pstrc, nbr, i, nbrf);
}

void	ft_print_po_cont_cont(t_printf *pstrc, unsigned long long nbr, int i,
		int nbrf[100])
{
	if (nbr == 4294967295u)
	{
		if (ft_strchr(pstrc->base, 'a'))
			pstrc->count += write(1, "ffffffff", 8);
		else if (ft_strchr(pstrc->base, 'A'))
			pstrc->count += write(1, "FFFFFFFF", 8);
		else
			pstrc->count += write(1, "4294967295", 10);
	}
	i = !pstrc->flags.pre && nbr == 0 && pstrc->flags.dot ? 0
		: ft_p(pstrc, nbr, nbrf, 0);
	if (pstrc->flags.dot)
		pstrc->flags.pre = pstrc->flags.pre >= i ? pstrc->flags.pre - i : 0;
	if (pstrc->flags.width > i)
		pstrc->flags.width = pstrc->flags.width - i;
	else
		pstrc->flags.width = pstrc->flags.width - i;
	if (pstrc->flags.minus)
		pstrc->count += ft_repeat(' ', pstrc->flags.width -
		pstrc->flags.pre - ft_print_hashtag(pstrc, nbr, 0), 1);
}

void	ft_print_p(t_printf *pstrc)
{
	unsigned long long	pointer;

	if (!(pointer = (unsigned long long)va_arg(pstrc->ap, long long)))
	{
		pstrc->flags.hashtag = 2;
		ft_print_po("0123456789abcdef", pstrc, 0);
	}
	else
	{
		pstrc->flags.hashtag = 2;
		ft_print_po("0123456789abcdef", pstrc, pointer);
	}
}
