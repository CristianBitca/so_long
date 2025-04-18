/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:02:06 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/15 18:02:07 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_custom_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	dst = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(dst))
		return (NULL);
	ft_strlcpy(dst, s1, s1_len + 1);
	ft_strlcpy((dst + s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (dst);
}

char	**ft_dup_map(t_game *game, char **map)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = ft_calloc(sizeof(char *), game->map_height + 1);
	if (!buffer)
		return (NULL);
	while (i < game->map_height)
	{
		buffer[i] = ft_strdup(map[i]);
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == WALL_CHAR
		|| map[y][x] == VALID_CHAR)
		return ;
	map[y][x] = VALID_CHAR;
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	ft_free_map(t_game *game, char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (i++ < game->map_height)
			free(map[i]);
		free(map);
	}
}
