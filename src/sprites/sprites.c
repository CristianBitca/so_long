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

	game->sprites.floor = mlx_xpm_file_to_image(mlx,
			"assets/void.xpm", &width, &height);
	if (game->sprites.floor == NULL)
		ft_print_error(XPM_FLOOR, game);
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
	game->sprites.wall = mlx_xpm_file_to_image(mlx,
			"assets/wall.xpm", &width, &height);
	if (game->sprites.wall == NULL)
		ft_print_error(XPM_FLOOR, game);
}
