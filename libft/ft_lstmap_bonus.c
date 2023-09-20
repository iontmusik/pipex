/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:08:29 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/06 14:32:33 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newele;
	t_list	*aux;

	newlist = NULL;
	aux = lst;
	while (aux)
	{
		newele = ft_lstnew((*f)(aux->content));
		if (!newele)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newele);
		aux = aux->next;
	}
	return (newlist);
}
