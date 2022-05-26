/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etisha <etisha@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:11:25 by etisha            #+#    #+#             */
/*   Updated: 2022/02/18 17:11:30 by etisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_ESC	53
# define KEY_UP		13
# define KEY_DOWN	1
# define KEY_RIGHT	2
# define KEY_LEFT	0

typedef struct s_game
{
	void	*img;
	char	*mlx;
	void	*win;
	char	**matrix;
	char	**collect;
	char	**dragon;
	char	**exit;
	char	**player;
	char	**wall;
	char	**playerp;
	char	*gameover;
	int		x;
	int		y;
	int		chest;
	int		steps;
}	t_game;

/* SO_LONG FUNCTIONS */
void	ft_exam_ber(char *argv);
void	ft_exam(t_game *game);
t_game	*ft_write_map(char *argv);
void	ft_free_memory(t_game *game);
void	ft_free_memory_success(t_game *game);
void	ft_free_sprites_memory(t_game *game);
void	ft_null_game_struct(t_game *game);
void	ft_null_matrix(t_game *game, int size);
void	ft_malloc_sprites(t_game *game);
void	ft_putnbr_fd(int n, int fd);
void	ft_save_info(t_game *game);
void	ft_put_enemy(t_game *game);
void	ft_open_window(t_game *game);
int		ft_render_next_frame(t_game *game);
int		ft_input(int keycode, t_game *game);
int		ft_press_x(t_game *game);
char	ft_next_step(int x, int y, t_game *game, int keycode);
void	ft_go(t_game *game, int keycode);
void	ft_collect_in_map(t_game *game);
void	ft_where_player(t_game *game);
void	ft_render_wall(t_game *game, int x, int y);
void	ft_render_collect(t_game *game, int x, int y);
void	ft_render_emp_exit(t_game *game, int x, int y);
void	ft_render_act_exit(t_game *game, int x, int y);
void	ft_render_sdragon(t_game *game, int x, int y);
void	ft_render_game_over(t_game *game, int x, int y);
void	ft_render_player(t_game *game, char c, int x, int y);
void	ft_render_player_port(t_game *game, char c, int x, int y);

/* GNL FUNCTIONS */
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_read_file(char *line, char *reminder, int fd);
char	*ft_find_line(char *reminder);
void	ft_new_reminder(char *reminder);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_free_reminder(char *reminder);
char	*ft_copy_in_line(char *line, char *reminder);
char	*ft_copy_from_read(char *line, char *reminder);

/* ITOA FUNCTIONS */
char	*ft_itoa(int n);

#endif
