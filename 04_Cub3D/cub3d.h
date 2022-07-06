/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:57:20 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 21:10:36 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include <stdint.h>

# define MAYOUB_POWER 100000000000
# ifndef RENDERER_THREAD_COUNT
#  define RENDERER_THREAD_COUNT 10
# endif

# define LROTATE 123
# define RROTATE 124
# define FORWARD 13
# define OPEN 14
# define BACKWARDS 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define TAB 48

# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6
# define KB_PRESS 2
# define KB_RELEASE 3
# define BOOMBOOM 17

# define WWIDTH 1600
# define WHEIGHT 900

typedef struct s_image {
	void			*mlx;
	void			*img;
	void			*win;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}				t_image;

typedef struct s_ray {
	double			our_x;
	double			our_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			total_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				sprite_side;
	double			step_size;
	double			const_rad;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				x_tex;
	double			y_tex;
	double			y_tex_step;
	int				forward;
	int				backwards;
	int				left;
	int				right;
	float			rot_left;
	float			rot_right;
	int				open_door;
	long			sprite_hit_x;
	long			sprite_hit_y;
	double			sprite_x;
	double			sprite_y;
	double			transform_x;
	double			transform_y;
	double			sprite_scr_x;
	double			sprite_height;
	double			sprite_width;
	int				sprite_draw_start_x;
	int				sprite_draw_start_y;
	int				sprite_draw_end_x;
	int				sprite_draw_end_y;
}		t_ray;

typedef struct s_info
{
	char			*full_file;
	int				x_size;
	int				y_size;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	unsigned int	f_color;
	unsigned int	c_color;
	unsigned int	fog_color;
	unsigned int	fog_enabled;
	unsigned int	enemies_count;
	char			**map;
	int				map_width;
	int				map_height;
	int				x_spawn;
	int				y_spawn;
	char			spawn_dir;
	char			*start;
}				t_info;

typedef struct s_tex
{
	t_image			n_img;
	t_image			e_img;
	t_image			s_img;
	t_image			w_img;
	t_image			sprite_img;
}				t_tex;

typedef struct s_controller
{
	int	mouse_grabbed;
	int	first_input;
	int	x;
	int	y;
}	t_controller;

typedef struct s_animable
{
	unsigned long		last_update;
	unsigned int		frame_time;
	t_image				*frames;
	unsigned int		frame_count;
	unsigned int		frame_pointer;
}	t_animable;

typedef struct s_hands
{
	t_animable		animator;
	t_image			*idle_frames;
	unsigned int	idle_frames_time;
	unsigned int	idle_frames_count;
	int				x;
	int				y;
}	t_hands;

typedef struct s_everything {
	t_image			image;
	t_image			minimap;
	t_ray			ray;
	t_info			info;
	t_tex			tex;
	t_controller	controller;
	t_hands			hands;
	t_animable		*animables[1024];
	int				animables_len;
	bool			redraw;
	bool			enemy_redraw;
	long			x_depth[WWIDTH];
}			t_everything;

// You did a structure with all others structures inside ?
// Yes
// How is called?
// Everything
//                      -Almost a meme

typedef struct s_color {
	int				r;
	int				g;
	int				b;
	int				color;
}				t_color;

//	update.c

void			environnement_update(t_everything *all);

//	init.c			Initialization functions

int				init_input(t_everything *all, int argc, char *cub_file);
int				init_textures(t_everything *all);
int				init_mlx(t_everything *all, char *win_name);
int				init_raycaster(t_everything *all);

//	parse.c			Parsing cub file functions

int				parse_res(int *size, char type);
int				parse_all(int fd, t_info *info);
int				parse_color(char *full_file, unsigned int *color, char *id);
int				parse_int(char *full_file, unsigned int *value, char *id);
int				parse_map(t_info *info, char *full_file);
int				parse_tex(t_info *info);

//	parsing_2.c
int				parse_int(char *full_file, unsigned int *le_int, char *id);
int				parse_color_unrequired(char *f, unsigned int *c, char *i);

//	check_info.c	Check cub file information functions

int				check_rgb(char **split, t_color *color_s);
int				check_spawn(t_info *info);
int				get_spawn_pos(t_info *info);
int				spawn_guns(t_everything *all, t_info *info);

//	check_map.c		Check whether map is valid functions

int				find_map(char *str);
int				check_row(char **map, int y_pos);
int				check_firstlast(char **map, int height);
int				check_spots(char **map, int x, int y);
int				check_map(t_info *info);

//	raycast.c		Raycasting calculation functions

void			set_ray_pos(t_everything *all, t_ray *our_ray, int x);
void			set_ray_len(t_ray *ray);
void			perform_dda(t_everything *all, t_ray *our_ray);
void			set_projection(t_ray *ray, t_info *info);

//	render.c		Rendering image to window

int				draw_bg(t_everything *all, int min, int max);
int				set_tex(t_everything *all, t_ray *r, t_image wall_img);
int				draw_tex(t_everything *all, t_ray *our_ray,
					t_image wall_img, int s_len);
void			draw_img(t_everything *all);
int				draw_img_threaded(t_everything *all);

//	hooks.c			Key hook functions

int				key_pressed(int keycode, t_everything *all);
int				key_released(int keycode, t_everything *all);
int				destroy_window(t_everything *all);

// mouse_hooks.c

int				handle_tab(t_everything *all);
int				mouse_pressed(int button, int x, int y, t_everything *all);
void			mouse_movement(int x, int y, t_everything *all);

//	move.c			Move player functions

int				spawn_dir(t_everything *all);
int				update_and_draw(t_everything *all);
int				move_player(t_everything *all, double x, double y);
int				rotate(t_everything *all, double radius);

//	utils_mlx.c		MLX functions but better

int				show_img(t_everything *all);
int				file_to_img(t_image *img, char *filename);
void			put_pixel(t_image *img, int x, int y, int color);

//	aux.c			Nice stuff

void			put_pix_bg(t_everything *all, int y, int color);
int				is_notmap(char c);
int				free_all(t_info *info, int stage);

//	color.c			RGB function

int				create_rgb(int r, int g, int b);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				gen_darker_color(int color, int factor);
int				blend_color(int src, int dst, float blend);
float			get_blending_by_dst(t_everything *all, int dist);

//	errors.c		Error functions

int				error_msg(char *message);
int				success_msg(char *message);

//	fake_libft.c (beacuse me and the homies only fake libft)

char			**free_bi_dimensional(char **array);
int				rows_counter(char **array);
int				ft_set_in_set(char *s1, char *s2);
int				check_only_digits(char *str);
int				theres_a_digit(char *str);
int				ft_inset(char *s1, char c);
char			*line_creator(char *str, char *needle);
int				read_everything(int fd, char **line);
char			*ft_strstr(const char *haystack, const char *needle);
void			strcopy(char *dst, const char *src);
int				first_index(char *str, char c);
bool			is_map_line(char *line, int i);

//void			init_gun_sprite(t_everything *all, t_sprite *s, int x, int y);

/* anim.c */
int				anim_get_frame_count(char *path);
t_image			*anim_get_frames(t_everything *all, char *path,
					unsigned int *frame_count);
void			animator_init(t_animable *a, t_image *frames,
					unsigned int fc, int ft);

int				minimap_init(t_everything *all);
void			minimap_generate(t_everything *all);

void			draw(t_everything *all);
void			display(t_everything *all);

int				get_thread_id(bool reset);

int				init_environnement(t_everything *all);

void			perform_dda_bonus(t_everything *all, t_ray *ray);
void			perform_adequate_drawings(t_everything *all, t_ray *ray, int x);
void			project_and_draw_sprites(t_everything *a, t_ray *r, void *d);

int				init_player(t_everything *all);
int				switch_door(t_everything *all);

# define AND &&
# define OR ||

#endif