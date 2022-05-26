/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:03:52 by etisha            #+#    #+#             */
/*   Updated: 2022/02/16 20:03:56 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_put_image(t_game *game, char c, int x, int y)
{
	int		w;
	int		h;
	char	*relative_path;

	relative_path = NULL;
	if (c == '0')
		return (0);
	else if (c == '1')
		relative_path = game->wall;
	else if (c == 'C')
		relative_path = game->collect;
	else if (c == 'E')
		relative_path = game->exit;
	else if (c == 'P')
		relative_path = game->player;
	else if (c == 'p')
		relative_path = game->playerp;
	game->img = mlx_xpm_file_to_image(game->mlx, relative_path, &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
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
	ft_render_next_frame(game);
}

int	ft_press_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_memory_sucsess(game);
	return (0);
}
