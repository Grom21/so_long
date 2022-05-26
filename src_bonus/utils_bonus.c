/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:11:42 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:11:43 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_sprites_memory(t_game *game)
{
	if (game->collect)
		free (game->collect);
	if (game->dragon)
		free (game->dragon);
	if (game->exit)
		free (game->exit);
	if (game->player)
		free (game->player);
	if (game->wall)
		free (game->wall);
	if (game->playerp)
		free (game->playerp);
}

void	ft_free_memory(t_game *game)
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
	exit (1);
}

void	ft_null_game_struct(t_game *game)
{
	game->img = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->matrix = NULL;
	game->collect = NULL;
	game->dragon = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->playerp = NULL;
	game->gameover = NULL;
}

void	ft_null_matrix(t_game *game, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		game->matrix[i] = NULL;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + '0';
		write (fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
