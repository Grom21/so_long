/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:09:00 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:09:03 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_exam_square(t_game *game)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	if (game->matrix[x])
		y = ft_strlen(game->matrix[x]);
	x++;
	while (game->matrix[x])
	{
		z = ft_strlen(game->matrix[x]);
		if (y != z)
		{
			write (2, "Error\nMap is bad(\n", 18);
			ft_free_memory(game);
		}
		x++;
	}
}

static void	ft_chek_up_and_down_map(t_game *game, int size)
{
	int	i;

	i = 0;
	while (game->matrix[size][i])
	{
		if (game->matrix[size][i] != '1')
		{
			write (2, "Error\nMap is bad(\n", 18);
			ft_free_memory(game);
		}
		i++;
	}
}

static void	ft_exam_surrounded(t_game *game)
{
	int	i;
	int	size;
	int	flag;

	flag = 0;
	size = 0;
	while (game->matrix[size])
		size++;
	ft_chek_up_and_down_map(game, size - 1);
	while (--size > 0)
	{
		i = ft_strlen(game->matrix[size]) - 1;
		if (game->matrix[size][0] != '1' || game->matrix[size][i] != '1')
			flag = 1;
	}
	ft_chek_up_and_down_map(game, size);
	if (flag == 1)
	{
		write (2, "Error\nMap is bad(\n", 18);
		ft_free_memory(game);
	}
}

static int	ft_exam_min_elements(t_game *game, int size, int exit, int collect)
{
	int	start;
	int	i;

	start = 0;
	while (--size > 0)
	{
		i = 0;
		while (game->matrix[size][i])
		{
			if (game->matrix[size][i] == 'E')
				exit = 1;
			if (game->matrix[size][i] == 'C')
				collect = 1;
			if (game->matrix[size][i] == 'P')
				start++;
			if (game->matrix[size][i] != '0' && game->matrix[size][i] != '1' \
			&& game->matrix[size][i] != 'E' && game->matrix[size][i] != 'C' \
			&& game->matrix[size][i] != 'P')
				start = -2000000000;
		i++;
		}
	}
	if (exit == 0 || collect == 0 || start != 1)
		return (1);
	return (0);
}

void	ft_exam(t_game *game)
{
	int	size;
	int	exit;
	int	collect;
	int	result;

	ft_exam_square(game);
	ft_exam_surrounded(game);
	size = 0;
	while (game->matrix[size])
		size++;
	size = size - 1;
	exit = 0;
	collect = 0;
	result = ft_exam_min_elements(game, size, exit, collect);
	if (result == 1)
	{
		write (2, "Error\nMap is bad(\n", 18);
		ft_free_memory(game);
	}
}
