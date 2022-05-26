/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:11:53 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:11:55 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_put_image(t_game *game, char c, int x, int y)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		ft_render_wall(game, x, y);
	else if (c == 'C')
		ft_render_collect(game, x, y);
	else if (c == 'E')
		ft_render_emp_exit(game, x, y);
	else if (c == 'e')
		ft_render_act_exit(game, x, y);
	else if (c == 'S')
		ft_render_sdragon(game, x, y);
	else if (c == 'G')
		ft_render_game_over(game, x, y);
	else if (c == 'P' || c == 'L' || c == 'U' || c == 'D')
		ft_render_player(game, c, x, y);
	else if (c == 'p' || c == 'l' || c == 'u' || c == 'd')
		ft_render_player_port(game, c, x, y);
	return (0);
}

int	ft_render_next_frame(t_game *game)
{
	int	i1;
	int	i2;

	mlx_clear_window(game->mlx, game->win);
	i1 = 0;
	while (game->matrix[i1])
	{
		i2 = 0;
		while (game->matrix[i1][i2])
		{
			ft_put_image(game, game->matrix[i1][i2], i2 * 50, i1 * 50);
			i2++;
		}
		i1++;
	}
	usleep (180000);
	return (0);
}

void	ft_open_window(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	x = ft_strlen(game->matrix[0]) * 50;
	y = 0;
	while (game->matrix[y])
		y++;
	y = y * 50;
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
}

int	ft_press_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_memory_success(game);
	return (0);
}
