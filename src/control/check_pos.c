/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:56:12 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/18 15:56:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_key_press(int key, t_game *game)
{
	if (key == ESC_KEY)
		game->key[0] = 1;
	if (key == W_KEY)
		game->key[1] = 1;
	if (key == S_KEY)
		game->key[2] = 1;
	if (key == A_KEY)
		game->key[3] = 1;
	if (key == D_KEY)
		game->key[4] = 1;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int key, t_game *game)
{
	if (key == ESC_KEY)
		game->key[0] = 0;
	if (key == W_KEY)
		game->key[1] = 0;
	if (key == S_KEY)
		game->key[2] = 0;
	if (key == A_KEY)
		game->key[3] = 0;
	if (key == D_KEY)
		game->key[4] = 0;
	return (EXIT_SUCCESS);
}

void	ft_check_pos(t_game *game, int x, int y)
{
	if (game->map[y][x] == EXIT_CHAR
		&& game->wallet == game->coin)
		ft_exit_game(game);
	if (game->map[y][x] == COIN_CHAR)
		game->wallet++;
	game->move++;
}
