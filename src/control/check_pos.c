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
	game->key = key;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int key, t_game *game)
{
	game->key = key;
	return (EXIT_SUCCESS);
}

void	ft_check_pos(t_game *game, int x, int y)
{
	if (game->map[y][x] == EXIT_CHAR)
		ft_exit_game(game);
	if (game->map[y][x] == COIN_CHAR)
	{
		game->wallet++;
		printf("You collected 1 coin now you have: %d", game->wallet);
	}
}
