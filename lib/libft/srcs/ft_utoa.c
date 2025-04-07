/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:11:52 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/08 13:11:54 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_unsignedint(unsigned int num)
{
	int	i;

	i = 1;
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*buffer;
	int		l;

	l = ft_count_unsignedint(n);
	buffer = ft_calloc(l + 1, sizeof(char));
	if (!buffer)
		return (0);
	if (n == 0)
		buffer[0] = '0';
	while (l)
	{
		buffer[l - 1] = '0' + (n % 10);
		n = n / 10;
		l--;
	}
	return (buffer);
}
