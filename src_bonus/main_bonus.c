/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:10:24 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:10:26 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exam_ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	while (argv[i] != '.' && i > 0)
		i--;
	if (i == 0 || argv[i + 1] == '\0')
	{
		write (2, "Error\nWrong map name\n", 21);
		exit (EXIT_SUCCESS);
	}
	if (argv[i + 1] != 'b' || argv[i + 2] != 'e' || \
	argv[i + 3] != 'r' || argv[i + 4] != '\0')
	{
		write (2, "Error\nWrong map name\n", 21);
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		write (2, "Error\nWrong arguments!\n", 23);
		return (0);
	}
	ft_exam_ber(argv[1]);
	game = ft_write_map(argv[1]);
	ft_exam(game);
	ft_save_info(game);
	ft_put_enemy(game);
	ft_open_window(game);
	mlx_loop_hook(game->mlx, ft_render_next_frame, (void *)game);
	mlx_hook(game->win, 2, 0, ft_input, game);
	mlx_hook(game->win, 17, 0, ft_press_x, game);
	mlx_loop(game->mlx);
}
