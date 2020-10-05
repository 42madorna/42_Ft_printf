/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:04:19 by madorna-          #+#    #+#             */
/*   Updated: 2020/09/23 19:47:41 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** #1. The string to output.
** #2. The file descriptor on which to write.
**
** Outputs the string ’s’ to the given file
** descriptor, followed by a newline.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int	nl;

	if (!s)
		return ;
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
	nl = '\n';
	write(fd, &nl, 1);
}
