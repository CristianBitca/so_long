/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:27:00 by cbitca            #+#    #+#             */
/*   Updated: 2025/01/06 18:27:01 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putpointer(void *ptr)
{
	int	res;

	res = 0;
	if (!ptr)
		return (pf_putstr("(nil)"));
	res += pf_putstr("0x");
	res += pf_putnbr_hexa(*(unsigned long *)&ptr, 'x');
	return (res);
}
