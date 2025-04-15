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
# define WALL_ERROR "Map should be surrounded by walls.\n"
# define BAD_CHAR "Map cointain an invalid character.\n"
# define PLAYER_ERROR "Map should contain one PLAYER character (P)"
# define COIN_ERROR "Map should contain at least one COIN character (C)"
# define EXIT_ERROR "Map should contain one EXIT character (E)"
# define RECTANGULAR_ERROR "Map is not rectangular\n"

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
	int		player;
	int		coin;
	int		exit;
}	t_game;

void	ft_init_map(t_game *game, char *map_file);
void	ft_check_file(t_game *game, char *map_file);
void	ft_init_map_info(t_game *game, char *map_file);
void	ft_check_map(t_game *game);

void	ft_print_error(char *error_msg, t_game *game);
void	ft_free_game(t_game *game);

char	*ft_custom_strjoin(char *s1, char *s2);

void	ft_check_elements(t_game *game);
void	ft_check_wall(t_game *game);
void	ft_req_elemtents(t_game *game);
void	ft_check_rectangular(t_game *game);

#endif 