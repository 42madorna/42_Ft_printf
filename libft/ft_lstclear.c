/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:36:07 by madorna-          #+#    #+#             */
/*   Updated: 2020/07/23 00:54:59 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		list = *lst;
		*lst = list->next;
		free(list);
	}
	*lst = NULL;
}
