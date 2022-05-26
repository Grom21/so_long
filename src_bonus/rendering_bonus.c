/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:10:34 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:10:36 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_wall(t_game *game, int x, int y)
{
	int			i;
	int			w;
	int			h;

	i = rand() % 3;
	game->img = mlx_xpm_file_to_image(game->mlx, game->wall[i], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	ft_render_collect(t_game *game, int x, int y)
{
	int			i;
	int			w;
	int			h;

	i = rand() % 3;
	game->img = mlx_xpm_file_to_image(game->mlx, game->collect[i], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	ft_render_emp_exit(t_game *game, int x, int y)
{
	int			w;
	int			h;

	game->img = mlx_xpm_file_to_image(game->mlx, game->exit[4], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	ft_render_act_exit(t_game *game, int x, int y)
{
	static int	i;
	int			w;
	int			h;

	game->img = mlx_xpm_file_to_image(game->mlx, game->exit[i], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
	i++;
	if (i > 3)
		i = 0;
}

void	ft_render_sdragon(t_game *game, int x, int y)
{
	int			i;
	int			w;
	int			h;

	i = rand() % 3;
	game->img = mlx_xpm_file_to_image(game->mlx, game->dragon[i], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}
