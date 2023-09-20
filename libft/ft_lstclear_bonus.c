/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:00:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/02 17:52:01 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*free_elem;

	if (!lst)
		return ;
	elem = *lst;
	while (elem)
	{
		free_elem = elem;
		elem = elem->next;
		ft_lstdelone(free_elem, del);
	}
	*lst = NULL;
}
