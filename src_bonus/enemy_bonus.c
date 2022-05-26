/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:08:47 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:08:50 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_enemy(t_game *game)
{
	int	i1;
	int	i2;

	i1 = -1;
	while (game->matrix[++i1])
	{
		i2 = -1;
		while (game->matrix[i1][++i2])
		{
			if (game->matrix[i1][i2] == '0' && rand() % 10 <= 1)
				game->matrix[i1][i2] = 'S';
		}
	}
}

void	ft_where_player(t_game *game)
{
	char	**p;
	int		x;
	int		y;

	p = game->matrix;
	x = -1;
	while (p[++x])
	{
		y = -1;
		while (p[x][++y])
		{
			if (p[x][y] == 'P' || p[x][y] == 'p' || p[x][y] == 'L' \
			|| p[x][y] == 'l' || p[x][y] == 'U' || p[x][y] == 'u' \
			|| p[x][y] == 'D' || p[x][y] == 'd' || p[x][y] == 'G')
				break ;
		}
		if (p[x][y] == 'P' || p[x][y] == 'p' || p[x][y] == 'L' \
			|| p[x][y] == 'l' || p[x][y] == 'U' || p[x][y] == 'u' \
			|| p[x][y] == 'D' || p[x][y] == 'd' || p[x][y] == 'G')
			break ;
	}
	game->x = x;
	game->y = y;
}

void	ft_free_memory_success(t_game *game)
{
	int	x;

	x = 0;
	if (game->matrix)
	{
		while (game->matrix[x] != NULL)
		{
			free(game->matrix[x]);
			x++;
		}
		free(game->matrix);
		game->matrix = NULL;
	}
	ft_free_sprites_memory(game);
	free (game);
	exit (EXIT_SUCCESS);
}
