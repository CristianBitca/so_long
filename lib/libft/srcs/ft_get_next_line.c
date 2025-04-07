/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:18:29 by cbitca            #+#    #+#             */
/*   Updated: 2025/01/08 16:18:30 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rest(char *line, char *buffer)
{
	int		to_copy;
	char	*new_line;

	new_line = ft_strchr(line, '\n');
	to_copy = 0;
	if (new_line)
	{
		to_copy = new_line - line + 1;
		ft_strcpy(buffer, new_line + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buffer[0] = '\0';
	}
	line[to_copy] = '\0';
}

char	*get_new_line(int fd, char *line, char *buffer)
{
	char	*new_line;
	int		count;

	if (line && ft_strchr(line, '\n'))
		return (line);
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		new_line = ft_strchr(buffer, '\n');
		line = ft_strjoin(line, buffer);
		if (new_line)
			break ;
	}
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = ft_strdup(buffer[fd]);
	line = get_new_line(fd, line, buffer[fd]);
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	rest(line, buffer[fd]);
	return (line);
}
