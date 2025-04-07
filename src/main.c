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

int	ft_exit_game(void *mlx)
{
	mlx = 0;
	return(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	if (argc == 2)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
		mlx_hook(mlx, 17, 0, &ft_exit_game, mlx);
		mlx_loop(mlx);
	}
	argc = 0;
	argv = 0;
}
