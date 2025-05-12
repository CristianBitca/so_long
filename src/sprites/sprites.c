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

	width = 0;
	height = 0;
	ft_map_sprites1(mlx, game, width, height);
	ft_map_sprites2(mlx, game, width, height);
	ft_char_sprites1(mlx, game, width, height);
	ft_char_sprites2(mlx, game, width, height);
}

void	ft_map_sprites1(void *mlx, t_game *game, int width, int height)
{
	game->sprites.u_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/u_wall.xpm", &width, &height);
	if (!game->sprites.u_wall)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.d_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/d_wall.xpm", &width, &height);
	if (!game->sprites.d_wall)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.l_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/l_wall.xpm", &width, &height);
	if (!game->sprites.l_wall)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.r_wall = mlx_xpm_file_to_image(mlx,
			"assets/map/r_wall.xpm", &width, &height);
	if (!game->sprites.r_wall)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.floor = mlx_xpm_file_to_image(mlx,
			"assets/map/void.xpm", &width, &height);
	if (!game->sprites.floor)
		ft_print_error(XPM_FLOOR, game);
}

void	ft_map_sprites2(void *mlx, t_game *game, int width, int height)
{
	game->sprites.collectible = mlx_xpm_file_to_image(mlx,
			"assets/coin.xpm", &width, &height);
	if (!game->sprites.collectible)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.exit = mlx_xpm_file_to_image(mlx,
			"assets/exit.xpm", &width, &height);
	if (!game->sprites.exit)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.player = mlx_xpm_file_to_image(mlx,
			"assets/player.xpm", &width, &height);
	if (!game->sprites.player)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.r_wall_c = mlx_xpm_file_to_image(mlx,
			"assets/map/r_wall_c.xpm", &width, &height);
	if (!game->sprites.r_wall_c)
		ft_print_error(XPM_FLOOR, game);
	game->sprites.l_wall_c = mlx_xpm_file_to_image(mlx,
			"assets/map/l_wall_c.xpm", &width, &height);
	if (!game->sprites.l_wall_c)
		ft_print_error(XPM_FLOOR, game);
}

void	ft_char_sprites1(void *mlx, t_game *game, int width, int height)
{
	game->c_xt[1] = mlx_xpm_file_to_image(mlx,
			"assets/font/1.xpm", &width, &height);
	if (!game->c_xt[1])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[2] = mlx_xpm_file_to_image(mlx,
			"assets/font/2.xpm", &width, &height);
	if (!game->c_xt[2])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[3] = mlx_xpm_file_to_image(mlx,
			"assets/font/3.xpm", &width, &height);
	if (!game->c_xt[3])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[4] = mlx_xpm_file_to_image(mlx,
			"assets/font/4.xpm", &width, &height);
	if (!game->c_xt[4])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[5] = mlx_xpm_file_to_image(mlx,
			"assets/font/5.xpm", &width, &height);
	if (!game->c_xt[5])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[6] = mlx_xpm_file_to_image(mlx,
			"assets/font/6.xpm", &width, &height);
	if (!game->c_xt[6])
		ft_print_error(XPM_FLOOR, game);
}

void	ft_char_sprites2(void *mlx, t_game *game, int width, int height)
{
	game->c_xt[7] = mlx_xpm_file_to_image(mlx,
			"assets/font/7.xpm", &width, &height);
	if (!game->c_xt[7])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[8] = mlx_xpm_file_to_image(mlx,
			"assets/font/8.xpm", &width, &height);
	if (!game->c_xt[8])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[9] = mlx_xpm_file_to_image(mlx,
			"assets/font/9.xpm", &width, &height);
	if (!game->c_xt[9])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[0] = mlx_xpm_file_to_image(mlx,
			"assets/font/0.xpm", &width, &height);
	if (!game->c_xt[0])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[10] = mlx_xpm_file_to_image(mlx,
			"assets/font/slash.xpm", &width, &height);
	if (!game->c_xt[10])
		ft_print_error(XPM_FLOOR, game);
	game->c_xt[11] = mlx_xpm_file_to_image(mlx,
			"assets/font/void_counter.xpm", &width, &height);
	if (!game->c_xt[11])
		ft_print_error(XPM_FLOOR, game);
}
