/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:30:16 by madorna-          #+#    #+#             */
/*   Updated: 2020/10/04 21:18:17 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			dot;
	int			wildcard;
	int			hashtag;
	int			plus;
	int			space;
	int			width;
	int			pre;
	int			neg;
}				t_flags;

typedef struct	s_printf
{
	size_t		count;
	char		*fmt;
	t_flags		flags;
	va_list		ap;
	char		*base;
}				t_printf;

int				ft_printf(char *fmt, ...);
void			ft_check_conv(t_printf *pstrc);
int				ft_check_post_conv(char fmt);
void			ft_check_flags(t_printf *pstrc);
void			ft_check_size(t_printf *pstrc);
void			ft_print_char(t_printf *pstrc);
void			ft_check_asterisk(t_printf *pstrc);
void			ft_print_string(t_printf *pstrc);
void			ft_print_p(t_printf *pstrc);
int				ft_repeat(char c, int width, int print);
void			ft_print_nbr(char *base, t_printf *pstrc, int nbr);
void			ft_print_pct(t_printf *pstrc, char c);
int				ft_nb(t_printf *pstrc, long long int nbr, int nbrf[100], int p);
void			ft_print_u(char *base, t_printf *pstrc, unsigned int nbr);
void			ft_print_u_cont(t_printf *pstrc, unsigned int nbr, int i,
				int nbrf[100]);
void			ft_print_nbr_cont(t_printf *pstrc, int nbr, int i,
				int nbrf[100]);
int				ft_print_hashtag(t_printf *pstrc, unsigned int nbr, int p);
int				ft_p(t_printf *pstrc, unsigned long long nbr, int nbrf[100],
				int p);
void			ft_print_po_cont(t_printf *pstrc, unsigned long long nbr, int i,
				int nbrf[100]);
void			ft_print_po_cont_cont(t_printf *pstrc, unsigned long long nbr,
				int i, int nbrf[100]);
void			ft_print_u_cont_cont(t_printf *pstrc, unsigned int nbr, int i,
				int nbrf[100]);

#endif
