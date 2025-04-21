/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:56:14 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/16 18:56:16 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_init_game(t_game *game, char *map_file)
{
	ft_init_sprites(game->mlx, game);
	ft_init_map(game, map_file);
	ft_render(game);
}
