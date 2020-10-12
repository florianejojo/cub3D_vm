/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:57:37 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/10 16:20:00 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# include "keycode.h"

# define SAVE_FILE "screenshot.bmp"
# define RAYSPEED 0.1
# define PLANE 0.5

typedef struct		s_check
{
	short			full_elements_detected;
	short			tab_elements_ok;
	short			R;
	short			textures;
	short			F;
	short			C;
}					t_check;

typedef enum		s_error
{
	SUCCESS,
	WRONG_ARGS,
	INVALID_ELEMENTS,
	LINE_NOT_CLOSED,
	MAP_NOT_CLOSED,
	WRONG_CHAR,
	MAP_ERROR,
	INVALID_FILE,
	MALLOC_FAILED,
	FILE_NOT_OPENED,
	NO_PLAYER_POS,
	TO_MANY_PLAYER_POS,
	ERROR_RES,
	ERROR_COLORS,
	WRONG_TEX,
	ERROR_START_END,
	MLX_FAIL,
	CALC_RAY_FAIL,
	IMG_FAIL,
	ERROR_SPRITES,
	ERROR_SAVE,
}					t_error;

typedef struct		s_header
{
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bbp;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_total;
	unsigned int	clr_important;
	}				t_header;

typedef struct		s_save_bmp
{
	int				fd;
	double			padding;
	t_header		header;
	
}					t_save_bmp;

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int 	b;
}					t_rgb;

typedef struct		s_colors
{
	t_rgb			rgb_C;
	t_rgb			rgb_F;

}					t_colors;

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*addr;
	int				bits_pp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_coordf
{
	double			x;
	double			y;
}					t_coordf;

typedef struct		s_coordi
{
	int				x;
	int				y;
}					t_coordi;

typedef struct		s_ray
{
	t_coordi		map;
	t_coordf		dir;
	t_coordf		old_dir;
	t_coordf		plane;
	t_coordf 		old_plane;	
	double 			**buff;
	t_coordf 		raydir;
	double 			speed;
	double 			camera;
	t_coordf 		deltadist;
	t_coordf 		sidedist;
	double 			perpwalldist;
	t_coordf 		step;
	int 			hit;
	int 			side;
	double 			lineheight;
	int 			drawstart;
	int 			drawend;
	unsigned int	color;
	t_rgb			color_rgb;
	char			*color_char;
	t_coordf		wall;
	t_coordi		tex;
	double			tex_step;
	double			tex_pos;
} 					t_ray;

typedef struct		s_res
{
	int				width;
	int				height;

}					t_res;

typedef struct		s_textures_path
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*S;
}					t_textures_path;

typedef struct		s_sprites
{	
	
	
	int				nb;
	char			*str;
	double			x;
	double			y;
	double 			inv_det;
	t_coordf		transform;
	t_coordi		screen;
	int				height;
	t_coordi		drawstart;
	t_coordi		drawend;
	int				width;
	t_coordi		tex;
	unsigned int	color;
}	t_sprites;

typedef struct		s_map
{
	char			**map;
	int				nb_lines;
	int				nb_char;
	t_res			res;
	int				i;
	int				j;
	int				start_line;
	int				end_line;
	char			player_dir;
	t_coordf		player_pos;
}					t_map;

typedef struct		s_mvt
{
	int				up;
	int				dwn;
	int				lft;
	int				rgt;
	int				side_r;
	int				side_l;
}					t_mvt;

typedef struct		s_env
{
	t_textures_path t_textures_path;
	t_map			t_map;
	t_res			res_max;
	int				sizex;
	int				sizey;
	t_colors		t_colors;
	t_check			t_check;
	t_error			error;
	int				error_type;
	t_ray			ray;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*img;
	t_img			*img_tex_NO;
	t_img			*img_tex_SO;
	t_img			*img_tex_WE;
	t_img			*img_tex_EA;
	t_img			*img_tex_S;
	t_sprites		sprites;
	double			*zbuffer;
	int				*order;
	double 			*distance;
	double			*sprite_pos_x;
	double 			*sprite_pos_y;
	int				tex_width;
	int				tex_height;
	t_mvt			mvt;
	int				check_calc;
	int				line;
	t_save_bmp 		bmp;
	int 			save;
	int				i;
	int				j;
	int				l;

}					t_env;

char	**ft_split_cub(t_env *env, char const *s, char c);
int		make_map(char *file, t_env *env);
void	make_tab(char *file, t_env *env);
int		check_textures(t_env *env);
int		pars_textures(t_env *env, int i, int j);
void	set_res_max(t_env *env);
int		pars_resolution(t_env *env, int i, int j);
int		pars_colors(t_env *env, int i, int j);
void	parsing();
int		pars_map(t_env *env);
int		check_map(t_env *env);
void	check_first_line(t_env *env);
int		print_error(int error, t_env *env);
int		skip_wsp(int i, int j, t_env *env);
int		skip_wsp_revers(int i, int j, t_env *env);
int		find_wall_up(t_env *env, int i, int j);
int		find_wall_down(t_env *env, int i, int j);
int		treat_file(char *file, t_env *env);
int		elems(int i, int j, t_env *env);
int 	line_closed(int i, char *line, t_env *env);
int		check_char(int i, int j, t_env *env);
int		is_wsp(int i, int j, t_env *env);
int		init_raycasting(t_env *env);
void	pick_color(t_env *env);
void	draw_line(t_env *env, int x, int drawstart, int drawend);
int		raycasting(t_env *env);
void	moves(t_env *env);
void	init_vectors(t_env *env, int x);
void	calc_step(t_env *env);
int		quit(t_env *env);
void	calc_size_screen_sprites(t_env *env);
void	calc_textures_data(t_env *env);
void	calc_draw_infos(t_env *env);
int		calc_data_raycasting(t_env *env, int x);
void	init_vectors(t_env *env, int x);
void	calc_step(t_env *env);
void	perform_DDA(t_env *env);
void	calc_perpwalldist(t_env *env);
void	calc_draw_infos(t_env *env);
t_img	*new_image(t_env *env, char *file);
void	init_calc_sprites(t_env *env, int i);
void	free_sprites(t_env *env);
void	draw_sprites(t_env *env);
int		add_sprites(t_env *env);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void    count_sprites(t_env *env);
void	free_all(t_env *env);
int		check_flag_save(char *str, t_env *env);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);
int		create_rgb(int r, int g, int b);
void	draw_line(t_env *env, int x, int drawstart, int drawend);
int		save_bmp(t_env *env);
void	free_img(t_img *img, t_env *env);

#endif