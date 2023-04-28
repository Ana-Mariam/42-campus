/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:10:01 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/04 16:10:02 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista;
	t_list	*nodo;

	lista = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		nodo = ft_lstnew(lst->content);
		if (!nodo)
		{
			ft_lstclear(&lista, del);
			return (NULL);
		}
		nodo->content = f(nodo->content);
		ft_lstadd_back(&lista, nodo);
		lst = lst->next;
	}
	return (lista);
}
