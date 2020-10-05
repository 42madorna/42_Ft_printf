/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:36:05 by madorna-          #+#    #+#             */
/*   Updated: 2020/09/22 22:58:47 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** #1. The character to output.
** #2. The file descriptor on which to write.
**
** Outputs the character ’c’ to the given file
** descriptor.
*/

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
