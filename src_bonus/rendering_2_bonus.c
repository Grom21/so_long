/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:24:23 by etisha            #+#    #+#             */
/*   Updated: 2022/02/20 17:24:26 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_game_over(t_game *game, int x, int y)
{
	int			w;
	int			h;

	game->img = mlx_xpm_file_to_image(game->mlx, game->gameover, &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	ft_render_player(t_game *game, char c, int x, int y)
{
	int		w;
	int		h;
	char	*s1;
	char	*s2;

	if (c == 'P')
		game->img = mlx_xpm_file_to_image(game->mlx, game->player[2], &w, &h);
	else if (c == 'L')
		game->img = mlx_xpm_file_to_image(game->mlx, game->player[1], &w, &h);
	else if (c == 'U')
		game->img = mlx_xpm_file_to_image(game->mlx, game->player[3], &w, &h);
	else if (c == 'D')
		game->img = mlx_xpm_file_to_image(game->mlx, game->player[0], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
	s1 = "Steps=";
	s2 = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, x, y, 0x00ffffff, s1);
	mlx_string_put(game->mlx, game->win, x + 42, y, 0x00ffffff, s2);
	free (s2);
}

void	ft_render_player_port(t_game *game, char c, int x, int y)
{
	int			w;
	int			h;

	if (c == 'p')
		game->img = mlx_xpm_file_to_image(game->mlx, game->playerp[2], &w, &h);
	else if (c == 'l')
		game->img = mlx_xpm_file_to_image(game->mlx, game->playerp[1], &w, &h);
	else if (c == 'u')
		game->img = mlx_xpm_file_to_image(game->mlx, game->playerp[3], &w, &h);
	else if (c == 'd')
		game->img = mlx_xpm_file_to_image(game->mlx, game->playerp[0], &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}
