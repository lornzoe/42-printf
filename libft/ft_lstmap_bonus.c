/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:32:57 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/10 19:35:31 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	newlist;
	t_list	*node;

	if (!lst || !f | !del)
		return (NULL);
	newlist.next = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&(newlist.next), del);
			return (NULL);
		}
		ft_lstadd_back(&(newlist.next), node);
		lst = lst->next;
	}
	return (newlist.next);
}
