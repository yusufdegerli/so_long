/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:36:00 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 19:03:04 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN -1
# define LEFT -1
# define RIGHT -1
# define ESC 53
# define LEFT_AN "images/character_left.xpm"
# define RIGHT_AN "images/character_right.xpm"
# define UP_AN "images/character_up.xpm"
# define DOWN_AN "images/character_down.xpm"

typedef struct s_arg
{
	int		valid_e;
	int		move;
	int		fail;
	int		tmp_coin_count;
	int		success;
	int		coin_count;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
	int		past_x;
	int		past_y;
	int		line_count;
	char	**mat;
	char	**map;
	char	**tmp_map;
	void	*mlx;
	void	*win;
	void	*mlx_win;
	void	*wall;
	void	*player;
	void	*img_exit;
	void	*colec;
	void	*back;
	void	*enemy;
	void	*left_animation;
	void	*right_animation;
	void	*up_animation;
	void	*down_animation;
}				t_arg;

void	map_width(int fd, char *map);

void	ft_put(t_arg *arg, void *img, int x, int y);

void	ft_read_map(t_arg *arg, char *str);

void	ft_map_init(char *str);

void	ft_line_len(t_arg *arg, char *str);

void	ft_free_map(t_arg *arg);

int		ft_exit(t_arg *arg);

int		ft_action(int key, t_arg *arg);

void	ft_map_mani(t_arg *arg, int x, int y);

void	ft_numb_of_elem_check(t_arg *arg);

void	ft_add(t_arg *arg, int x, int y);

void	ft_put_win(t_arg *arg);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	init_param(t_arg *arg);

void	ft_ber_check(char *map_name);

void	ft_map_check(t_arg *arg);

void	ft_fe_count_check(t_arg *arg);

void	*ft_memset(void *s, int c, size_t len);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strrchr(const char *s, int c);

char	*ft_strdup(const char *s1);

char	*ft_itoa(int n);

void	ft_rectangular_ctl(t_arg *arg);

void	ft_surrounded_wall_check(t_arg *arg);

void	ft_leftright_wall_check(t_arg *arg);

void	ft_validmap_check(t_arg *arg, int x, int y);

void	ft_path_check(t_arg *arg);

void	ft_sprite(t_arg *arg, int x, int y);

void	init_param2(t_arg *arg);

int		ft_map_init2(t_arg *arg);

void	ft_action2(t_arg *arg);

void	ft_create_xpm2(t_arg *arg);

#endif
