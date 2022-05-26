/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:54:45 by etisha            #+#    #+#             */
/*   Updated: 2022/02/16 19:54:48 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_next_step(int x, int y, t_game *game, int keycode)
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

static void	ft_go(int x, int y, t_game *game, int keycode)
{
	char	next;

	if (game->matrix[x][y] == 'p')
		game->matrix[x][y] = 'E';
	else
		game->matrix[x][y] = '0';
	next = ft_next_step(x, y, game, keycode);
	if (keycode == KEY_UP && next != 'E')
		game->matrix[x - 1][y] = 'P';
	else if (keycode == KEY_UP && next == 'E')
		game->matrix[x - 1][y] = 'p';
	else if (keycode == KEY_DOWN && next != 'E')
		game->matrix[x + 1][y] = 'P';
	else if (keycode == KEY_DOWN && next == 'E')
		game->matrix[x + 1][y] = 'p';
	else if (keycode == KEY_RIGHT && next != 'E')
		game->matrix[x][y + 1] = 'P';
	else if (keycode == KEY_RIGHT && next == 'E')
		game->matrix[x][y + 1] = 'p';
	else if (keycode == KEY_LEFT && next != 'E')
		game->matrix[x][y - 1] = 'P';
	else if (keycode == KEY_LEFT && next == 'E')
		game->matrix[x][y - 1] = 'p';
}

static void	ft_win_game(t_game *game)
{
	int	x;
	int	y;
	int	collect;
	int	flag;

	collect = 0;
	flag = 0;
	x = -1;
	while (game->matrix[++x])
	{
		y = -1;
		while (game->matrix[x][++y])
		{
			if (game->matrix[x][y] == 'p')
				flag = 1;
			if (game->matrix[x][y] == 'C')
				collect++;
		}
	}
	if (flag == 1 && collect == 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		write (1, "You win!\n", 9);
		ft_free_memory_sucsess(game);
	}
}

static void	ft_move(int keycode, t_game *game, int x, int y)
{
	static int	i;

	if (ft_next_step(x, y, game, keycode) == '1')
		return ;
	ft_go(x, y, game, keycode);
	ft_render_next_frame(game);
	i++;
	write (1, "Steps = ", 8);
	ft_putnbr_fd(i, 1);
	write (1, "\n", 1);
	ft_win_game(game);
}

int	ft_input(int keycode, t_game *game)
{
	int	x;
	int	y;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_free_memory_sucsess(game);
	}
	x = -1;
	while (game->matrix[++x])
	{
		y = -1;
		while (game->matrix[x][++y])
		{
			if (game->matrix[x][y] == 'P' || game->matrix[x][y] == 'p')
				break ;
		}
		if (game->matrix[x][y] == 'P' || game->matrix[x][y] == 'p')
			break ;
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN \
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		ft_move(keycode, game, x, y);
	return (0);
}
