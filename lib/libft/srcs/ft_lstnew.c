/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:14:52 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/18 14:14:54 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = ft_calloc(sizeof(t_list), 1);
	if (!l)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}

/*int main(void)
{
	t_list *l;

	l = ft_lstnew("test");
	printf("%s", (char *)l->content);
	free (l);
	return (0);
}*/