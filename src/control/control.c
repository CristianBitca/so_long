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
	{
		ft_move_up(game);
		printf("up\n");
	}
	if (game->key[2])
	{
		ft_move_down(game);
		printf("down\n");
	}
	if (game->key[3])
	{
		ft_move_left(game);
		printf("left\n");
	}
	if (game->key[4])
	{
		ft_move_right(game);
		printf("right\n");
	}
	usleep(16000);
	return (EXIT_SUCCESS);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		ft_check_pos(game, game->player_x, game->player_y - 1);
		game->map[game->player_y - 1][game->player_x] = PLAYER_CHAR;
		game->player_y--;
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		ft_check_pos(game, game->player_x, game->player_y + 1);
		game->map[game->player_y + 1][game->player_x] = PLAYER_CHAR;
		game->player_y++;
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		ft_check_pos(game, game->player_x - 1, game->player_y);
		game->map[game->player_y][game->player_x - 1] = PLAYER_CHAR;
		game->player_x--;
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		ft_check_pos(game, game->player_x + 1, game->player_y);
		game->map[game->player_y][game->player_x + 1] = PLAYER_CHAR;
		game->player_x++;
	}
}
