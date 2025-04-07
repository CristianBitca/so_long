/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:03:16 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/03 12:03:18 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (size && n > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, n * size);
	return (ptr);
}
