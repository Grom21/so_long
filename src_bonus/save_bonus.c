/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:10:53 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:10:56 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_save_info2(t_game *game)
{
	game->player[0] = "./sprites/playerdown.xpm";
	game->player[1] = "./sprites/playerleft.xpm";
	game->player[2] = "./sprites/playerright.xpm";
	game->player[3] = "./sprites/playerup.xpm";
	game->playerp[0] = "./sprites/playerdownport.xpm";
	game->playerp[1] = "./sprites/playerleftport.xpm";
	game->playerp[2] = "./sprites/playerrightport.xpm";
	game->playerp[3] = "./sprites/playerupport.xpm";
	game->steps = 0;
}

void	ft_save_info(t_game *game)
{
	game->collect[0] = "./sprites/collect1.xpm";
	game->collect[1] = "./sprites/collect2.xpm";
	game->collect[2] = "./sprites/collect3.xpm";
	game->collect[3] = "./sprites/collect4.xpm";
	game->dragon[0] = "./sprites/drag1.xpm";
	game->dragon[1] = "./sprites/drag2.xpm";
	game->dragon[2] = "./sprites/drag3.xpm";
	game->dragon[3] = "./sprites/drag4.xpm";
	game->exit[0] = "./sprites/exit1.xpm";
	game->exit[1] = "./sprites/exit2.xpm";
	game->exit[2] = "./sprites/exit3.xpm";
	game->exit[3] = "./sprites/exit4.xpm";
	game->exit[4] = "./sprites/exitclozed.xpm";
	game->wall[0] = "./sprites/wall1.xpm";
	game->wall[1] = "./sprites/wall2.xpm";
	game->wall[2] = "./sprites/wall3.xpm";
	game->wall[3] = "./sprites/wall4.xpm";
	game->gameover = "./sprites/gameover.xpm";
	ft_save_info2(game);
}

void	ft_malloc_sprites(t_game *game)
{
	game->collect = (char **)malloc(sizeof(char *) * 4);
	game->dragon = (char **)malloc(sizeof(char *) * 4);
	game->exit = (char **)malloc(sizeof(char *) * 5);
	game->player = (char **)malloc(sizeof(char *) * 4);
	game->wall = (char **)malloc(sizeof(char *) * 4);
	game->playerp = (char **)malloc(sizeof(char *) * 4);
	if (!game->collect || !game->dragon || !game->exit || !game->player \
		|| !game->wall || !game->playerp)
	{
		write (2, "Error\nDont allocate memory(\n", 28);
		ft_free_memory(game);
	}
}
