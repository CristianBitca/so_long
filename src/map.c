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
	// ft_check_map(game);
	for (int i = 0; i < game->map_height; i++)
		printf("%s", game->map[i]);
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
	char	*line;
	char	*buffer;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		ft_print_error(FILE_OPEN_ERROR, game);
	line = ft_get_next_line(fd);
	if (!line)
		ft_print_error(EMPTY_FILE, game);
	game->map_width = ft_strlen(line) - 1;
	buffer = ft_strdup("");
	buffer = ft_custom_strjoin(buffer, line);
	while (line)
	{
		game->map_height++;
		line = ft_get_next_line(fd);
		if (line)
			buffer = ft_custom_strjoin(buffer, line);
	}
	free(line);
	game->map = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}

void	ft_check_map(t_game *game)
{
	ft_check_rectangular(game);
	ft_check_elements(game);
	ft_check_wall(game);
	ft_req_elemtents(game);
}
