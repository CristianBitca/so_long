/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:45:11 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/16 19:45:12 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_init_sprites(void *mlx, t_game *game)
{
	int	width;
	int	height;

	ft_map_sprites(mlx, game);
	game->sprites.collectible = mlx_xpm_file_to_image(mlx,
			"assets/coin.xpm", &width, &height);
	if (game->sprites.collectible == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.exit = mlx_xpm_file_to_image(mlx,
			"assets/exit.xpm", &width, &height);
	if (game->sprites.exit == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.player = mlx_xpm_file_to_image(mlx,
			"assets/player.xpm", &width, &height);
	if (game->sprites.player == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.r_wall_c = mlx_xpm_file_to_image(mlx,
			"assets/map/r_wall_c.xpm", &width, &height);
	if (game->sprites.r_wall_c == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.l_wall_c = mlx_xpm_file_to_image(mlx,
			"assets/map/l_wall_c.xpm", &width, &height);
	if (game->sprites.l_wall_c == NULL)
		ft_print_error(XPM_FLOOR, game);
}

void	ft_map_sprites(void *mlx, t_game *game)
{
	int	width;
	int	height;

	game->sprites.u_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/u_wall.xpm", &width, &height);
	if (game->sprites.u_wall == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.d_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/d_wall.xpm", &width, &height);
	if (game->sprites.d_wall == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.l_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/l_wall.xpm", &width, &height);
	if (game->sprites.l_wall == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.r_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/r_wall.xpm", &width, &height);
	if (game->sprites.r_wall == NULL)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.floor = mlx_xpm_file_to_image(mlx,
			"assets/map/void.xpm", &width, &height);
	if (game->sprites.floor == NULL)
		ft_print_error(XPM_FLOOR, game);
}
