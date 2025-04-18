/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:21:04 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/07 20:21:05 by cbitca           ###   ########.fr       */
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
	mlx_destroy_image(game->mlx, game->sprites.floor);
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.player);
	mlx_destroy_image(game->mlx, game->sprites.exit);
	mlx_destroy_image(game->mlx, game->sprites.collectible);
	free(game);
}

int	ft_exit_game(t_game *game)
{
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), sizeof(t_game));
	if (argc != 2)
		ft_print_error(FILE_NAME, game);
	if (argc == 2)
	{
		game->mlx = mlx_init();
		if (!game->mlx)
			ft_print_error(MLX_INIT_ERROR, game);
		game->win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
		ft_init_game(game, argv[1]);
		mlx_hook(game->win, KEY_PRESS, 1L << 0, &ft_key_press, game);
		mlx_hook(game->win, KEY_RELEASE, 1L << 1, &ft_key_release, game);
		mlx_hook(game->win, CLOSE_ICON, 0, &ft_exit_game, game);
		mlx_loop_hook(game->mlx, &render, game);
		mlx_loop(game->mlx);
	}
}
