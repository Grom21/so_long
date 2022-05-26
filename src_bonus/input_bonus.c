/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:10:04 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:10:06 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	ft_next_step(int x, int y, t_game *game, int keycode)
{
	char	next;

	next = 0;
	if (keycode == KEY_UP)
		next = game->matrix[x - 1][y];
	else if (keycode == KEY_DOWN)
		next = game->matrix[x + 1][y];
	else if (keycode == KEY_RIGHT)
		next = game->matrix[x][y + 1];
	else if (keycode == KEY_LEFT)
		next = game->matrix[x][y - 1];
	return (next);
}

static void	ft_win_game(t_game *game)
{
	int		x;
	int		y;
	int		flag;
	char	**p;

	p = game->matrix;
	flag = 0;
	x = -1;
	while (p[++x])
	{
		y = -1;
		while (p[x][++y])
		{
			if (p[x][y] == 'p' || p[x][y] == 'l' || p[x][y] == 'u' \
			|| p[x][y] == 'd')
				flag = 1;
		}
	}
	if (flag == 1 && game->chest == 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		write (1, "You win!\n", 9);
		ft_free_memory_success(game);
	}
}

static void	ft_activate_portal(t_game *game)
{
	int		x;
	int		y;
	char	**p;

	ft_collect_in_map(game);
	p = game->matrix;
	x = -1;
	while (p[++x])
	{
		y = -1;
		while (p[x][++y])
		{
			if (p[x][y] == 'E' && game->chest == 0)
				p[x][y] = 'e';
		}
	}
}

static void	ft_move(int keycode, t_game *game)
{
	if (ft_next_step(game->x, game->y, game, keycode) == '1')
		return ;
	ft_go(game, keycode);
	game->steps++;
	ft_activate_portal(game);
	ft_win_game(game);
}

int	ft_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_free_memory_success(game);
	}
	ft_where_player(game);
	if (game->matrix[game->x][game->y] == 'G')
		return (0);
	if (keycode == KEY_UP || keycode == KEY_DOWN \
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		ft_move(keycode, game);
	return (0);
}
