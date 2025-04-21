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

int	ft_render(t_game *game)
{
	ft_input_controller(game);
	ft_render_map(game, &game->sprites);
	return(EXIT_SUCCESS);
}

void	ft_render_map(t_game *game, t_textures *txt)
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
		ft_render_wall(game, txt, x, y);
	if (c == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->exit, x * 64, y * 64);
	if (c == COIN_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->collectible, x * 64, y * 64);
	if (c == PLAYER_CHAR)
		mlx_put_image_to_window(game->mlx, game->win, txt->player, x * 64, y * 64);
}

void	ft_render_wall(t_game *game, t_textures *txt, int x, int y)
{
	if (y == game->map_height - 1 && x == 0)
		mlx_put_image_to_window(game->mlx, game->win, txt->l_wall_c, x * 64, y * 64);
	else if (y == game->map_height - 1 && x == game->map_width - 1)
		mlx_put_image_to_window(game->mlx, game->win, txt->r_wall_c, x * 64, y * 64);
	else if (y == 0 && x != game->map_width - 1 && x != 0)
		mlx_put_image_to_window(game->mlx, game->win, txt->u_wall, x * 64, y * 64);
	else if (y == game->map_height - 1 && x != game->map_width - 1 && x != 0)
		mlx_put_image_to_window(game->mlx, game->win, txt->d_wall, x * 64, y * 64);
	else if (x == 0 && y != game->map_height - 1)
		mlx_put_image_to_window(game->mlx, game->win, txt->l_wall, x * 64, y * 64);
	else if (y != game->map_height - 1 && x == game->map_width - 1)
		mlx_put_image_to_window(game->mlx, game->win, txt->r_wall, x * 64, y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, txt->u_wall, x * 64, y * 64);

}