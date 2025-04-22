/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:52:50 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/22 12:52:52 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_print_error(char *error_msg, t_game *game)
{
	ft_free_game(game);
	ft_printf(ERROR);
	ft_printf(error_msg);
	exit(EXIT_FAILURE);
}

void	ft_free_game(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (i++ < game->map_height)
			free(game->map[i]);
		free(game->map);
	}
	ft_free_sprites1(game);
	ft_free_sprites2(game);
	free(game);
}

void	ft_free_sprites1(t_game *game)
{
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.player)
		mlx_destroy_image(game->mlx, game->sprites.player);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.collectible)
		mlx_destroy_image(game->mlx, game->sprites.collectible);
	if (game->sprites.d_wall)
		mlx_destroy_image(game->mlx, game->sprites.d_wall);
	if (game->sprites.l_wall)
		mlx_destroy_image(game->mlx, game->sprites.l_wall);
	if (game->sprites.l_wall_c)
		mlx_destroy_image(game->mlx, game->sprites.l_wall_c);
	if (game->sprites.r_wall)
		mlx_destroy_image(game->mlx, game->sprites.r_wall);
	if (game->sprites.r_wall_c)
		mlx_destroy_image(game->mlx, game->sprites.r_wall_c);
	if (game->sprites.u_wall)
		mlx_destroy_image(game->mlx, game->sprites.u_wall);
}

void	ft_free_sprites2(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (game->c_xt[i])
			mlx_destroy_image(game->mlx, game->c_xt[i]);
		i++;
	}
}

int	ft_exit_game(t_game *game)
{
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}
