/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:03:06 by etisha            #+#    #+#             */
/*   Updated: 2022/02/16 20:03:09 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_copy_in_matrix(int i, t_game *game, char *line, int size)
{
	int	x;

	x = -1;
	while (++x < size)
	{
		if (line[x] == '\n')
			game->matrix[i][x] = '\0';
		else
			game->matrix[i][x] = line[x];
	}
	game->matrix[i][x] = '\0';
}

static void	ft_save_map(int fd, t_game *game)
{
	static int		i;
	char			*line;
	int				size;

	line = get_next_line(fd);
	if (line)
	{
		size = ft_strlen(line);
		game->matrix[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (game->matrix[i] == NULL)
		{
			write (2, "Error\nDont allocate memory(\n", 28);
			ft_free_memory(game);
		}
		ft_copy_in_matrix(i, game, line, size);
		i++;
	}
	else
		game->matrix[i] = NULL;
	free (line);
}

static int	ft_size_of_matrix(char *argv)
{
	int		fd;
	char	*line;
	int		size;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	size = 0;
	if (line)
	{
		size++;
		free (line);
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			size++;
			free (line);
		}
	}
	close(fd);
	return (size);
}

static void	ft_malloc_matrix(char *argv, t_game *game)
{
	int		fd;
	int		size;

	size = ft_size_of_matrix(argv);
	game->matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (game->matrix == NULL)
	{
		write (2, "Error\nDont allocate memory(\n", 28);
		ft_free_memory(game);
	}
	ft_null_matrix(game, size);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error\nCant open file(\n", 21);
		ft_free_memory(game);
	}
	while (size >= 0)
	{
		ft_save_map(fd, game);
		size--;
	}
	close(fd);
}

t_game	*ft_write_map(char *argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		write (2, "Error\nDont allocate memory(\n", 28);
		exit (EXIT_SUCCESS);
	}
	ft_null_game_struct(game);
	ft_malloc_matrix(argv, game);
	return (game);
}
