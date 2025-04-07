/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:38:12 by cbitca            #+#    #+#             */
/*   Updated: 2024/12/03 13:38:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	unsigned int	l;
	char			*buffer;

	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (start + n > l)
		buffer = ft_calloc(l - start + 1, sizeof(char));
	else
		buffer = ft_calloc(n + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, &s[start], n + 1);
	return (buffer);
}

/*int	main(void)
{
	printf("%s\n", ft_substr("Hola", 0, 2365465462141132141));
	return (0);
}*/