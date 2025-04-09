/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:12:40 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/08 15:12:42 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_map(t_game *game, char *map_file)
{
	int	fd;

	if (!ft_check_file(map_file))
		return ;
	ft_init_map_info(game, map_file);
	fd = open(map_file, O_RDONLY);
	ft_read_map(game, fd);
	close(fd);
}

int	ft_check_file(char *map_file)
{
	int		fd;
	int		len_ext;
	int		len_fd;
	char	*line;

	len_fd = ft_strlen(map_file);
	len_ext = ft_strlen(BER_EXTENSION);
	map_file += len_fd - len_ext;
	if (ft_strncmp(map_file, BER_EXTENSION, len_ext))
		return (ft_printf(EXTENSION_ERROR), FALSE);
	map_file -= len_fd - len_ext;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ft_printf(FILE_OPEN_ERROR), close(fd), FALSE);
	line = ft_get_next_line(fd);
	if (!line)
		return (ft_printf(EMPTY_FILE), close(fd), free(line), FALSE);
	free(line);
	return (TRUE);
}

void	ft_init_map_info(t_game *game, char *map_file)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	line = ft_get_next_line(fd);
	game->map_width = ft_strlen(line);
	game->map_height = 0;
	while (line)
	{
		free(line);
		line = ft_get_next_line(fd);
		game->map_height++;
	}
	game->map_area = game->map_height * game->map_width;
	close(fd);
}

void	ft_read_map(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	game->map = ft_calloc(game->map_height, sizeof(char *));
	line = ft_get_next_line(fd);
	game->map[i] = ft_strtrim(line, "\n");
	while (i < game->map_height)
	{
		free(line);
		line = ft_get_next_line(fd);
		i++;
		game->map[i] = ft_strtrim(line, "\n");
	}
	close(fd);
}

