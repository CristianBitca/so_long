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
	int	file;

	ft_init_map_info(game,map_file);
	file = 0;
	file = open(map_file, O_RDONLY);
	ft_read_map(game, file);
	close(file);

}

// If any leaks check here later.\/
void	ft_init_map_info(t_game *game, char *map_file)
{
	char	*line;
	int	fd;
	
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
	int	i;

	i = 0;
	game->map = ft_calloc(game->map_width * sizeof(char), game->map_height * sizeof(char *));
	i = 0;
	game->map[i] = ft_get_next_line(fd);
	while(i < game->map_height)
	{
		ft_printf("%s", game->map[i]);
		i++;
		game->map[i] = ft_get_next_line(fd);
	}
	i = 0;
	while(i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game = 0;
}

void	ft_check_map()
{

}
