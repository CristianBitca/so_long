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

void	ft_exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), sizeof(t_game));
	if (argc != 2)
		ft_printf("Enter the file name.");
	if (argc == 2)
	{
		ft_init_map(game, argv[1]);
		ft_exit_game(game);
	}
	argc = 0;
	argv = 0;
}
