/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:37:59 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/06 14:38:03 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	buffer = 0;
	if (s1 && set)
	{
		i = 0;
		j = ft_strlen(s1);
		while (ft_strchr(set, s1[i]))
			i++;
		while (ft_strchr(set, s1[j - 1]))
			j--;
		buffer = ft_substr(s1, i, j - i);
	}
	return (buffer);
}
