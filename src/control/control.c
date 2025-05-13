/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:26:30 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/17 17:26:31 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_input_controller(t_game *game)
{
	if (game->key[0])
		ft_exit_game(game);
	if (game->key[1])
		ft_move_up(game);
	if (game->key[2])
		ft_move_down(game);
	if (game->key[3])
		ft_move_left(game);
	if (game->key[4])
		ft_move_right(game);
	usleep(36000);
	return (EXIT_SUCCESS);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] != WALL_CHAR
		&& (game->map[game->p_y - 1][game->p_x] != EXIT_CHAR
		|| game->wallet == game->coin))
	{
		game->map[game->p_y][game->p_x] = VOID_CHAR;
		ft_check_pos(game, game->p_x, game->p_y - 1);
		game->map[game->p_y - 1][game->p_x] = PLAYER_CHAR;
		game->p_y--;
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] != WALL_CHAR
		&& (game->map[game->p_y + 1][game->p_x] != EXIT_CHAR
		|| game->wallet == game->coin))
	{
		game->map[game->p_y][game->p_x] = VOID_CHAR;
		ft_check_pos(game, game->p_x, game->p_y + 1);
		game->map[game->p_y + 1][game->p_x] = PLAYER_CHAR;
		game->p_y++;
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] != WALL_CHAR
		&& (game->map[game->p_y][game->p_x - 1] != EXIT_CHAR
		|| game->wallet == game->coin))
	{
		game->map[game->p_y][game->p_x] = VOID_CHAR;
		ft_check_pos(game, game->p_x - 1, game->p_y);
		game->map[game->p_y][game->p_x - 1] = PLAYER_CHAR;
		game->p_x--;
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] != WALL_CHAR
		&& (game->map[game->p_y][game->p_x + 1] != EXIT_CHAR
		|| game->wallet == game->coin))
	{
		game->map[game->p_y][game->p_x] = VOID_CHAR;
		ft_check_pos(game, game->p_x + 1, game->p_y);
		game->map[game->p_y][game->p_x + 1] = PLAYER_CHAR;
		game->p_x++;
	}
}
