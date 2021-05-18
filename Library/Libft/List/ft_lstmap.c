/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:25:54 by fgalaup           #+#    #+#             */
/*   Updated: 2021/03/16 16:05:41 by felix            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_elem;

	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		new_list_elem = ft_lstnew(f(lst->content));
		if (new_list_elem == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_list_elem);
		lst = lst->next;
	}
	return (new_list);
}
