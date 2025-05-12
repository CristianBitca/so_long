/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:14:57 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/22 17:14:58 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_count_coin(t_game *game)
{
	int	n;
	int	i;

	n = game->coin;
	i = 6;
	while (i != 3)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->c_xt[n % 10], i * 64, 0 * 64);
		n /= 10;
		i--;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->c_xt[10], i * 64, 0 * 64);
	n = game->wallet;
	while (i--)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->c_xt[n % 10], i * 64, 0 * 64);
		n /= 10;
	}
}

int	ft_count(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		i++;
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void	ft_count_move(t_game *game)
{
	int	i;
	int	n;
	int	c;

	i = game->map_width - 1;
	n = game->move;
	c = ft_count(n);
	while (c)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->c_xt[n % 10], i * 64, 0 * 64);
		n /= 10;
		i--;
		c--;
	}
}

void	ft_counter(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->c_xt[11], i * 64, 0 * 64);
		ft_count_coin(game);
		ft_count_move(game);
		i++;
	}
}
