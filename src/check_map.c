/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:27:53 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/08 20:27:54 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// // void	ft_check_walls(t_game *game)
// {
// 	// int	i;
// 	// int	j;

// 	// i = 0;
// 	// j = 0;
// 	// while (j < game->map_width - 1)
// 	// 	if (game->map[i][j++] != WALL_CHAR)
// 	// 		ft_print_error(WALL_ERROR, game);
// 	// i = game->map_height - 1;
// 	// j = 0;
// 	// while (j < game->map_width - 2)
// 	// {
// 	// 	if (game->map[i][j] != WALL_CHAR)
// 	// 		ft_print_error(WALL_ERROR, game);
// 	// 	j++;
// 	// }
// 	// i = 0;
// 	// while (i < game->map_height - 1)
// 	// 	if (game->map[i++][0] != WALL_CHAR)
// 	// 		ft_print_error(WALL_ERROR, game);
// 	// i = 0;
// 	// while (i < game->map_height)
// 	// 	if (game->map[i++][game->map_width - 2] != WALL_CHAR)
// 	// 		ft_print_error(WALL_ERROR, game);
// }	

// void	ft_check_chars(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		j = 0;
// 		while (j < 13)
// 		{
// 			if (game->map[i][j] != WALL_CHAR
// 				&& game->map[i][j] != PLAYER_CHAR
// 				&& game->map[i][j] != COIN_CHAR
// 				&& game->map[i][j] != EXIT_CHAR
// 				&& game->map[i][j] != VOID_CHAR)
// 				ft_print_error(BAD_CHAR, game);
// 			j++;
// 		}
// 		i++;
// 	}
// }