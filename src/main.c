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

#include "../include/so_long.h"

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
	while (i++ < game->map_height)
		free(game->map[i]);
	free(game->map);
	free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_printf("Enter the file name.");
	if (argc == 2)
	{
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		ft_init_map(game, argv[1]);
		ft_free_game(game);
	}
	argc = 0;
	argv = 0;
}
