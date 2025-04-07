/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:30:12 by cbitca            #+#    #+#             */
/*   Updated: 2024/11/29 13:30:13 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (n)
	{
		*(t_dest++) = *(t_src++);
		n--;
	}
	return (dest);
}
