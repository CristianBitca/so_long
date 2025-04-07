/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:56:06 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/18 15:56:07 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("node2");
	t_list	*node2 = ft_lstnew("node1");

	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	t_list	*temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/