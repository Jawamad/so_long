/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:38:43 by flmuller          #+#    #+#             */
/*   Updated: 2024/07/01 14:01:12 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <errno.h>

# define SIZE 64

typedef struct s_img
{
	int				size;
	void			*collectible;
	void			*enemy_f1;
	void			*exit_closed;
	void			*exit_opened;
	void			*ground;
	void			*p_back_f1;
	void			*p_face_f1;
	void			*p_left_f1;
	void			*p_right_f1;
	void			*wall;
	void			*win;
	void			*loose;
	void			*p_anim_f1;
	void			*p_anim_f2;
	void			*p_anim_f3;
	void			*p_anim_f4;
}	t_img;

typedef struct s_pos
{
	int				x;
	int				y;
}	t_pos;

typedef struct s_map_data
{
	char			**map;
	unsigned int	nb_column;
	unsigned int	nb_row;
	int				c_count;
	int				e_count;
	int				p_count;
	int				m_count;
	int				c_collected;
	int				width;
	int				height;
	t_pos			p_pos;
	t_pos			e_pos;
	t_pos			m_pos;
}	t_map_data;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	int				nb_moves;
	t_map_data		map_data;
	t_img			img;
	int				is_paused;
	int				loop;
	int				patrol_dir;
	int				curr_frame;
}		t_data;

/* so_long.c */
void			next_frame(t_data *data);
void			next_frame_re(t_data *data);
int				main(int ac, char **av);
int				render_frame(t_data *data);
void			check_ext(char *file);

/* ft_error.c */
void			ft_error(int code);
void			ft_error_data(t_data *data, int code);

/* gnl/get_next_line.c */
char			*get_next_line(int fd);

/* parsing.c */
void			map_checker(char *file, t_data *data);
void			check_rectangle(t_data *data);
void			count_tile(char c, t_data *data);
void			count_map_tile(t_data *data);
void			check_tiles(t_data *data);
/* path.c */
int				check_path(char **map);
void			valid_path(char *file, t_data *data);
void			flood_fill(char **map, t_pos pos);

/* init_map.c */
char			**fill_map(char *file);
void			init_map_data(t_data *data);
void			init_entities_pos(t_data *data);
void			set_pos(t_data *data, int x, int y);
int				check_nb_line(char *file);

/* display_img */
void			*convert_img(t_data *data, char *path);
void			set_img(t_data *data);
void			display_img(t_data *data, void *img, int y, int x);
void			put_img_to_map(t_data *data);
void			display_map(t_data *data);

/* utils.c */
unsigned int	ft_strlen_line(char *s);
void			display_black_rectangle(t_data *data, t_pos pos,
					int width, int height);

/* handlers */
void			quit_game(t_data *data);
int				close_window(t_data *data);
int				handle_events(int keycode, t_data *data);
void			count_move(t_data *data);
void			pause_game(t_data *data);

/* move.c */
void			move(t_data *data, int keycode);
void			*select_move_sprite(t_data *data, t_pos *new_pos);
t_pos			*gen_new_pos(t_data *data, int keycode);
void			enemy_patrol(t_data *data);
int				check_patrol_path(int x, int y, t_data *data);

/* finish.c */
void			loose(t_data *data);
void			win(t_data *data);
void			check_loose(t_data *data);
void			destroy_img(t_data *data);

#endif