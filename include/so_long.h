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
# define FILE_NAME "Enter the file name."
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
# define EMPTY_LINE "File contain empty line\n"
# define VALID_ERROR "This game is imposible to win.\n"
# define MLX_INIT_ERROR "mlx_init() fail\n"
# define XPM_FLOOR "XPM floor file error\n"
# define XPM_WALL "XPM wall file error\n"
# define XPM_PLAYER "XPM player file error\n"
# define XPM_EXIT "XPM exit file error\n"
# define XPM_COLLECTIBLE "XPM collectible file error\n"

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
	VOID_CHAR = '0',
	VALID_CHAR = 'V'
}	t_map_char;

typedef enum e_key_code {
	CLOSE_ICON = 17,
	ESC_KEY = 65307,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP_ARROW_KEY = 65362,
	DOWN_ARROW_KEY = 65364,
	LEFT_ARROW_KEY = 65361,
	RIGHT_ARROW_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
}	t_key_code;

typedef struct s_texture
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collectible;
} t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures 	sprites;
	char		**map;
	int		map_width;
	int		map_height;
	int		map_area;
	int		player_x;
	int		player_y;
	int		player;
	int		coin;
	int		exit;
	int		key[255];
}	t_game;

void	ft_init_game(t_game *game, char *map_file);
int	ft_exit_game(t_game *game);

void	ft_init_sprites(void *mlx, t_game *game);
void	ft_render(t_game *game, t_textures *txt);

void	ft_render_init(t_game *game, t_textures *txt, char c, int x, int y);

void	ft_init_map(t_game *game, char *map_file);
void	ft_check_file(t_game *game, char *map_file);
void	ft_init_map_info(t_game *game, char *map_file);
char	*ft_read_map(t_game *game, int fd);
void	ft_check_map(t_game *game);

void	ft_print_error(char *error_msg, t_game *game);
void	ft_free_game(t_game *game);

char	*ft_custom_strjoin(char *s1, char *s2);
char	**ft_dup_map(t_game *game, char **map);
void	ft_flood_fill(char **map, int x, int y);
void	ft_free_map(t_game *game, char **map);

void	ft_check_elements(t_game *game);
void	ft_check_wall(t_game *game);
void	ft_req_elemtents(t_game *game);
void	ft_check_rectangular(t_game *game);
void	ft_check_valid(t_game *game);

int	ft_controler(t_game *game);
int	ft_input_controller(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int	ft_key_press(int key, t_game *game);
int	ft_key_release(int key, t_game *game);
int	render(t_game *game);

#endif 