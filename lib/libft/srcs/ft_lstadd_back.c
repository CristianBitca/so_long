/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:00:50 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/18 18:00:51 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}

/*int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	t_list	*temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/
