/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:02:39 by etisha            #+#    #+#             */
/*   Updated: 2022/02/16 20:02:43 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_info(t_game *game)
{
	game->wall = "./sprites/wall1.xpm";
	game->collect = "./sprites/collect1.xpm";
	game->exit = "./sprites/exit1.xpm";
	game->player = "./sprites/playerright.xpm";
	game->playerp = "./sprites/playerrightport.xpm";
}
