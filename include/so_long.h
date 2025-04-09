/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:42:26 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/04 20:42:27 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/include/libft.h"

# define ERROR "ERROR\n"
# define BER_EXTENSION ".ber"
# define EXTENSION_ERROR "Map extension should be .ber"
# define EMPTY_FILE "Your file is empty.\n"
# define FILE_OPEN_ERROR "Fail to open file.\n"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef enum e_map_char
{
	WALL_CHAR = '1',
	PLAYER_CHAR = 'P',
	COIN_CHAR = 'C',
	EXIT_CHAR = 'E',
	VOID_CHAR = '0'
}	t_map_char;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		map_area;
	int		player_x;
	int		player_y;
}	t_game;

void	ft_init_map(t_game *game, char *map_file);
int		ft_check_file(char *map_file);
void	ft_init_map_info(t_game *game, char *map_file);
void	ft_read_map(t_game *game, int fd);

#endif