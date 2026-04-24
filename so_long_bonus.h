/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:20:43 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/24 14:42:37 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// ============================
// INCLUDE
// ============================

# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

// ============================
// MACROS
// ============================

// @KEYS

# ifndef ARROW_LEFT
#  define ARROW_LEFT 65361
# endif

# ifndef ARROW_UP
#  define ARROW_UP 65362
# endif

# ifndef ARROW_RIGHT
#  define ARROW_RIGHT 65363
# endif

# ifndef ARROW_DOWN
#  define ARROW_DOWN 65364
# endif

# ifndef KEY_A
#  define KEY_A 97
# endif

# ifndef KEY_W
#  define KEY_W 119
# endif

# ifndef KEY_D
#  define KEY_D 100
# endif

# ifndef KEY_S
#  define KEY_S 115
# endif

# ifndef SPACE
#  define SPACE 32
# endif

// UI

# ifndef ESC
#  define ESC 65307
# endif

# ifndef EVENT_CLOSE
#  define EVENT_CLOSE 17
# endif

// @map

# ifndef EXIT_MAP
#  define EXIT_MAP 'E'
# endif

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef COLLECTIBLES
#  define COLLECTIBLES 'C'
# endif

# ifndef WALL_MAP
#  define WALL_MAP '1'
# endif

// @RENDER

# define TILE_SIZE 32
# define NB_FRAMES 3
# define LEFT 0
# define RIGHT 1
# define MAX_WIDTH_WINDOW 1920
# define MAX_HEIGHT_WINDOW 1080

// image path

# define CHICKEN_L0 "textures/player/animation/chicken_left_0.xpm"
# define CHICKEN_L1 "textures/player/animation/chicken_left_1.xpm"
# define CHICKEN_L2 "textures/player/animation/chicken_left_2.xpm"
# define CHICKEN_R0 "textures/player/animation/chicken_right_0.xpm"
# define CHICKEN_R1 "textures/player/animation/chicken_right_1.xpm"
# define CHICKEN_R2 "textures/player/animation/chicken_right_2.xpm"
# define WALL_IMG "textures/walls/bush/wall_0.xpm"
# define FLOOR_IMG "textures/floor/grass/grass_0.xpm"
# define COLLECTIBLES_IMG "textures/collectibles/collectible.xpm"
# define EXIT_IMG "textures/exit/exit_0.xpm"
# define EXIT_CLOSED_IMG "textures/exit/exit_closed.xpm"

// Colors

# define COLOR_WHEAT

// ============================
// @STRUCTURE
// ============================

typedef struct s_img
{
	void	*wall;
	void	*collectibles;
	void	*exit_state;
	void	*exit_closed;
	void	*exit_open;
	void	*floor;
}				t_img;

typedef struct s_collectibles
{
	int		max_to_collect;
	int		collected_counter;
}				t_collectibles;

// player.direction : left 0, right 1

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		x_start_p;
	int		y_start_p;
	int		direction;
	int		frame;
	long	last_time;
	int		counter_move;
	void	*img_left[4];
	void	*img_right[4];

}				t_player;

typedef struct s_map
{
	char	**full_map;
	int		width;
	int		height;
}				t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				max_height;
	int				max_width;
	t_img			img;
	t_collectibles	collectibles;
	t_player		player;
	t_map			map;
}				t_data;

// ============================
// @FUNCTIONS
// ============================

// @parsing

int		map_invalid_format(char *map_str);
int		ft_str_format(char *string, char *sub_string);

// @events

int		handle_keypress(int keycode, void *param);
int		close_window(t_data *data);

// @map

int		read_map(char *map_name, t_data *data);
char	**ft_get_map(int fd);
int		ft_get_height(char **map);
int		ft_get_width(char *line);
int		map_not_rectangle_or_too_big(t_data *data);
int		map_not_enclosed_by_wall(t_data *data);
int		ft_first_line_check(char tile, t_data *data);
int		ft_last_line_check(char tile, int x, t_data *data);
int		ft_check_body_lines(char *line, t_data *data, int x);
char	**copy_map(char **map, int height);

// @path

int		not_valid_path(t_data *data);
void	flood_fill(char **map, int x, int y);
int		impossible_to_win(char **map);

// @components

int		check_components(t_data *data);
void	init_counts(int *p, int *e, int *c, int *x);
int		count_components(char tile, int *p, int *e, int *c);
void	init_start_player(char tile, int x, int y, t_data *data);
int		check_component_number(int p, int e, int c);
int		all_collectibles_collected(t_data *data);

// @initialization

void	*init_window(t_data *data);
void	init_hooks(t_data *data);
void	init_player_images(t_data *data);
void	*load_image(t_data *data, char *path);
void	init_textures(t_data *data);
void	init_map_images(t_data *data);

// @RENDER

int		render_animation(t_data *data);
void	draw_player(t_data *data);
void	update_player_animation(t_player *p);
void	draw_map(t_data *data);
void	handle_exit_img(t_data *data, int y, int x);
int		handle_exit_condition(t_data *data, char tile);
void	draw_max_collectible(t_data *data);

// @HOOK

int		close_esc(int keycode, t_data *data);

// player
void	move_player( t_data *data, int dx, int dy);
void	draw_counter(t_data *data);

// time

long	get_time(void);

// @error

int		mlx_error(void);
void	display_perror(void);
int		error_from_parsing(int ac, char *map_str);
void	display_error(char *error_msg);
int		error_args_number(int ac);

// @free

void	free_map(char **map);
void	free_images(t_data *data);
void	free_all(t_data *data);

#endif