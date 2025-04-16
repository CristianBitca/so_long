/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:21:10 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/15 16:21:11 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_map(t_game *game, char *map_file)
{
	ft_check_file(game, map_file);
	ft_init_map_info(game, map_file);
	ft_check_map(game);
}

void	ft_check_file(t_game *game, char *map_file)
{
	int		len_ext;
	int		len_fd;

	len_fd = ft_strlen(map_file);
	len_ext = ft_strlen(BER_EXTENSION);
	if (ft_strncmp(map_file + len_fd - len_ext, BER_EXTENSION, len_ext))
		ft_print_error(EXTENSION_ERROR, game);
}

void	ft_init_map_info(t_game *game, char *map_file)
{
	int		fd;
	char	*buffer;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		ft_print_error(FILE_OPEN_ERROR, game);
	buffer = ft_read_map(game, fd);
	if(!ft_strnstr(buffer, "\n\n", ft_strlen(buffer)))
		game->map = ft_split(buffer, '\n');
	else
		ft_print_error(EMPTY_LINE, game);
	free(buffer);
	close(fd);
}
char	*ft_read_map(t_game *game, int fd)
{
	char	*line;
	char	*file_content;

	line = ft_get_next_line(fd);
	if (!line)
		ft_print_error(EMPTY_FILE, game);
	game->map_width = ft_strlen(line) - 1;
	file_content = ft_strdup("");
	file_content = ft_custom_strjoin(file_content, line);
	while (line)
	{
		game->map_height++;
		line = ft_get_next_line(fd);
		if (line)
			file_content = ft_custom_strjoin(file_content, line);
	}
	free(line);
	return (file_content);
}

void	ft_check_map(t_game *game)
{
	ft_check_rectangular(game);
	ft_check_elements(game);
	ft_check_wall(game);
	ft_req_elemtents(game);
}
