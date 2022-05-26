/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:09:47 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:09:49 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_collect_in_map(t_game *game)
{
	int	x;
	int	y;

	game->chest = 0;
	x = -1;
	while (game->matrix[++x])
	{
		y = -1;
		while (game->matrix[x][++y])
		{
			if (game->matrix[x][y] == 'C')
				game->chest++;
		}
	}
}

static void	ft_gragon_kus(t_game *game, int keycode)
{
	if (keycode == KEY_UP)
		game->matrix[game->x - 1][game->y] = 'G';
	else if (keycode == KEY_DOWN)
		game->matrix[game->x + 1][game->y] = 'G';
	else if (keycode == KEY_RIGHT)
		game->matrix[game->x][game->y + 1] = 'G';
	else if (keycode == KEY_LEFT)
		game->matrix[game->x][game->y - 1] = 'G';
}

static void	ft_go_part_two(t_game *game, int keycode, char next)
{
	char	**p;
	int		x;
	int		y;

	p = game->matrix;
	x = game->x;
	y = game->y;
	if ((keycode == KEY_UP && next == 'E') || next == 'e')
		p[x - 1][y] = 'u';
	else if (keycode == KEY_UP && next != 'E')
		p[x - 1][y] = 'U';
	else if ((keycode == KEY_DOWN && next == 'E') || next == 'e')
		p[x + 1][y] = 'd';
	else if (keycode == KEY_DOWN && next != 'E')
		p[x + 1][y] = 'D';
	else if ((keycode == KEY_RIGHT && next == 'E') || next == 'e')
		p[x][y + 1] = 'p';
	else if (keycode == KEY_RIGHT && next != 'E')
		p[x][y + 1] = 'P';
	else if ((keycode == KEY_LEFT && next == 'E') || next == 'e')
		p[x][y - 1] = 'l';
	else if (keycode == KEY_LEFT && next != 'E')
		p[x][y - 1] = 'L';
}

void	ft_go(t_game *game, int keycode)
{
	char	next;
	char	**p;
	int		x;
	int		y;

	p = game->matrix;
	x = game->x;
	y = game->y;
	ft_collect_in_map(game);
	if ((p[x][y] == 'p' || p[x][y] == 'l' || p[x][y] == 'u' || p[x][y] == 'd') \
		&& game->chest != 0)
		p[x][y] = 'E';
	else if ((p[x][y] == 'p' || p[x][y] == 'l' || p[x][y] == 'u' \
			|| p[x][y] == 'd') && game->chest == 0)
		p[x][y] = 'e';
	else
		p[x][y] = '0';
	next = ft_next_step(game->x, game->y, game, keycode);
	if (next == 'S')
	{
		ft_gragon_kus(game, keycode);
		return ;
	}
	ft_go_part_two(game, keycode, next);
}
