/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:12:31 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/17 15:12:33 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	render(t_game *game)
{
	ft_input_controller(game);
	ft_render(game, &game->sprites);
	return(EXIT_SUCCESS);
}

void	ft_render(t_game *game, t_textures *txt)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (width < game->map_width)
		{
			ft_render_init(game, txt, game->map[height][width], width, height);
			width++; 
		}
		height++;
	}
}

void	ft_render_init(t_game *game, t_textures *txt, char c, int x, int y)
{
	if (c == VOID_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->floor, x * 64, y * 64);
	if (c == WALL_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->wall, x * 64, y * 64);
	if (c == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->exit, x * 64, y * 64);
	if (c == COIN_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->collectible, x * 64, y * 64);
	if (c == PLAYER_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->player, x * 64, y * 64);
}