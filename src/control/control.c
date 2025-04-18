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

int	ft_key_press(int key, t_game *game)
{
	game->key = key;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int key, t_game *game)
{
	game->key = key;
	return (EXIT_SUCCESS);
}

int	ft_input_controller(t_game *game)
{
	// if (game->key[])
	// 	ft_exit_game(game);
	if (game->key == W_KEY)
		ft_move_up(game);
	if (game->key == S_KEY)
		ft_move_down(game);
	if (game->key == A_KEY)
		ft_move_left(game);
	if (game->key == D_KEY)
		ft_move_right(game);
	return(EXIT_SUCCESS);
}

void	ft_move_up(t_game *game)
{	
	if (game->map[game->player_y - 1][game->player_x] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		game->map[game->player_y - 1][game->player_x] = PLAYER_CHAR;
		game->player_y--;
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		game->map[game->player_y + 1][game->player_x] = PLAYER_CHAR;
		game->player_y++;
	}
}

void	ft_move_left(t_game *game)
{	
	if (game->map[game->player_y][game->player_x - 1] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		game->map[game->player_y][game->player_x - 1] = PLAYER_CHAR;
		game->player_x--;
	}
}

void	ft_move_right(t_game *game)
{	
	if (game->map[game->player_y][game->player_x + 1] != WALL_CHAR)
	{
		game->map[game->player_y][game->player_x] = VOID_CHAR;
		game->map[game->player_y][game->player_x + 1] = PLAYER_CHAR;
		game->player_x++;
	}
}