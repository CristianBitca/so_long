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
	int	i;

	i = 0;
	ft_check_file(game, map_file);
	ft_init_map_info(game, map_file);
	ft_read_map(game, map_file);
	// while (i < game->map_width)
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
	// ft_check_map(game);
}

void	ft_check_file(t_game *game, char *map_file)
{
	int		fd;
	int		len_ext;
	int		len_fd;
	char	*line;

	len_fd = ft_strlen(map_file);
	len_ext = ft_strlen(BER_EXTENSION);
	map_file += len_fd - len_ext;
	if (ft_strncmp(map_file, BER_EXTENSION, len_ext))
		ft_print_error(EXTENSION_ERROR, game);
	map_file -= len_fd - len_ext;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_print_error(FILE_OPEN_ERROR, game);
	line = ft_get_next_line(fd);
	if (!line)
		ft_print_error(EMPTY_FILE, game);
	free(line);
	close(fd);
}

void	ft_init_map_info(t_game *game, char *map_file)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	line = ft_get_next_line(fd);
	game->map_width = ft_strlen(line) - 1;
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

void	ft_read_map(t_game *game, char	*map_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (i < game->map_height)
	{
		line = ft_get_next_line(fd);
		ft_printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
}

// void	ft_check_map(t_game *game)
// {
// 	// ft_check_walls(game);
// 	// ft_check_chars(game);

// }