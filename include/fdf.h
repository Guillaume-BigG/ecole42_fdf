/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:09:39 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/20 19:30:05 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line_bonus.h"
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

// MACROS
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define PI_G 3.14159265358979323846
# define MOUSE_LEFT 1
# define WHEEL_CLICK 2
# define MOUSE_RIGHT 3
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define PLUS 65451
# define MINUS 65453
# define A 97
# define S 115
# define D 100
# define F 102
# define G 103
# define Q 113
# define W 119
# define E 101
# define R 114
# define Z 122
# define X 120
# define C 99
# define V 118

// STRUCT

typedef struct s_cav
{
	float			x;
	float			y;
	float			z;
}					t_cav;

typedef struct s_color
{
	int				color;
	int				color_transparancy;
	int				color_red;
	int				color_green;
	int				color_blue;
}					t_color;

typedef struct s_coordinate
{
	float			ori_x;
	float			ori_y;
	float			ori_z;
	int				x;
	int				y;
	int				z;
	float			proj_x;
	float			proj_y;
	float			proj_z;
	int				color;
	int				color_transparancy;
	int				color_red;
	int				color_green;
	int				color_blue;
	int				max_z_pos;
	int				min_z_neg;
}					t_coordinate;

typedef struct s_map
{
	int				width;
	int				height;
	t_coordinate	**array;
}					t_map;

typedef struct s_one_line_map
{
	char			*map_in_one;
	char			**lines;
}					t_one_line_map;

typedef struct s_image
{
	void			*mlx_image;
	void			*img_address;
	int				img_bpp;
	int				img_line_length;
	int				img_endian;
}					t_image;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*window_ptr;
	float			zoom;
	float			scaling;
	float			depth;
	int				shift_x;
	int				shift_y;
	int				prev_mouse_x;
	int				prev_mouse_y;
	int				inc_x;
	int				inc_y;
	int				dx;
	int				dy;
	int				max_z_pos;
	int				min_z_neg;
	int				flag_color_given;
	unsigned int	color_background;
	int				color_line;
	int				color_words;
	int				pos_color;
	int				neg_color;
	int				flat_color;
	float			angle_rot_x;
	float			angle_rot_y;
	float			angle_rot_z;
	float			angle_cav;
	int				flag_isometric;
	int				flag_cav;
	t_image			image;
	t_map			map;
}					t_data;

// FUNCTIONS

/// Handling erreur
int					check_map(t_data *data, int width_check);
int					check_file_name(char *file_name);
int					number_arg(int argc);
int					check_folder(char *file_name);
int					check_file(char *file_name);

// Parsing map
int					read_map(char *file_name, t_data *data);
char				*ft_gnltomap(int fd);

// Allocation memory
int					array_allocation(t_data *data);
int					array_allocation_decimal(t_data *data);
void				free_map(t_data *data);
int					end_program(t_data *data);
void				check_split_space_alloc(char **tab,
						t_one_line_map *pre_map);
void				check_split_coma_alloc(char **tab, char **tab2,
						t_one_line_map *pre_map);
void				free_fill_array(char **tab1, char **tab2, int i, int j);
void				free_map_tab(char **tab);

// Initialization data
int					initialize_display(t_data *data);
void				initialize_map_pixel_loc(t_data *data);
void				initialize_hook(t_data *data);

// Handling drawing
int					render(t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				draw_menu(t_data *data);
void				draw_upper_line(t_data *data, int color);
void				draw_lower_line(t_data *data, int color);
void				reset_background(t_data *data, int color);

// Bresenhem algo and projections
void				line_bresenham(t_data *data, t_coordinate *start,
						t_coordinate *end);
void				isometric_projection(t_data *data,
						t_coordinate *coordinate);
void				cavalier_projection(t_data *data, t_coordinate *coordinate);

// Color
int					color_gradiant_pixel(int step, int num_steps,
						t_coordinate *start, t_coordinate *end);
int					data_color(t_data *data, t_coordinate *point);
void				ocean_blue_palette(t_data *data);
void				summer_sunset_palette(t_data *data);
void				lavender_palette(t_data *data);
void				white_palette(t_data *data);
void				black_palette(t_data *data);

// Math
int					ft_atoi_base_hex(char *str);
int					absolute(int x);
int					sign(int x);
int					maximun(int x, int y);
void				max_z(t_data *data);
void				min_z(t_data *data);

// Handling events
int					key_press_event(int keysym, t_data *data);
int					mouse_release_event(int button, int x, int y, t_data *data);
int					mouse_press_event(int button, int x, int y, t_data *data);

#endif