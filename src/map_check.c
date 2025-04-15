/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:27:18 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/15 18:27:19 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height - 1)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] != WALL_CHAR
				&& game->map[i][j] != PLAYER_CHAR
				&& game->map[i][j] != COIN_CHAR
				&& game->map[i][j] != EXIT_CHAR
				&& game->map[i][j] != VOID_CHAR)
				ft_print_error(BAD_CHAR, game);
			j++;
		}
		i++;
	}
}

void	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_width)
		if (game->map[i][j++] != WALL_CHAR)
			ft_print_error(WALL_ERROR, game);
	j--;
	while (i < game->map_height)
		if (game->map[i++][j] != WALL_CHAR)
			ft_print_error(WALL_ERROR, game);
	i--;
	while (j > -1)
		if (game->map[i][j--] != WALL_CHAR)
			ft_print_error(WALL_ERROR, game);
	j++;
	while (i > -1)
		if (game->map[i--][j] != WALL_CHAR)
			ft_print_error(WALL_ERROR, game);
}

void	ft_req_elemtents(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < game->map_height - 1)
	{
		j = 0;
		while (j++ < game->map_width - 1)
		{
			if (game->map[i][j] == PLAYER_CHAR)
				game->player++;
			if (game->map[i][j] == COIN_CHAR)
				game->coin++;
			if (game->map[i][j] == EXIT_CHAR)
				game->exit++;
		}
	}
	if (game->player != 1)
		ft_print_error(PLAYER_ERROR, game);
	if (game->coin < 1)
		ft_print_error(COIN_ERROR, game);
	if (game->exit != 1)
		ft_print_error(EXIT_ERROR, game);
}

void	ft_check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_width)
			ft_print_error(RECTANGULAR_ERROR, game);
		i++;
	}
}