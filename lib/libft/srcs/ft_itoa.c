/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:11:52 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/08 13:11:54 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_int(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		i++;
	while (num > 9 || num < -9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		l;

	l = ft_count_int(n);
	buffer = ft_calloc(l + 1, sizeof(char));
	if (!buffer)
		return (0);
	if (n == 0)
		buffer[0] = '0';
	if (n < 0)
		buffer[0] = '-';
	while (n)
	{
		if (n < 0)
			buffer[l - 1] = '0' + ((n % 10) * -1);
		else
			buffer[l - 1] = '0' + (n % 10);
		n = n / 10;
		l--;
	}
	return (buffer);
}
