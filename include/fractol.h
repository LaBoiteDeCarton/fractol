#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define EXEC_PROTO "Usage : fractol <fractal-type>\n"
# define ERR_NOARG "Please enter some arguments\n"
# define ERR_MALLOC "We got some trouble to malloc capitain\n"
# define ERR_FRACTTYPE "Never heard about that fractal before\n"
# define ERR_BAD2ARG "The precision should be only digits, like '42'\n"
# define ERR_TOOMUCHARG "Wait wait wait, you talk too much, tell me only the fractal name please"

# define H_MEDIUM_SIZE 720
# define V_MEDIUM_SIZE 480
# define H_LARGE_SIZE 1080
# define V_LARGE_SIZE 720

# define K_A_DOWN 125
# define K_A_UP	126
# define K_A_LEFT 123
# define K_A_RIGHT 124
# define K_I 34
# define K_P 35
# define K_M 41
# define K_A 12
# define K_C 8
# define K_1 18
# define K_2 19
# define K_3 20
# define K_4 21
# define K_ESC 53
# define K_TAB 48
# define K_SHIFT 258
# define K_SHIFT2 257

typedef struct s_fractol		t_fractol;
typedef struct s_complexe 		t_complexe;
typedef struct s_key_stat		t_key_stat;
typedef struct s_col			t_col;
typedef struct s_color			t_color;
typedef struct s_case			t_case;

struct s_color
{
	int t;
	int r;
	int g;
	int b;
};

typedef enum s_col_set_type
{
	white,
	white_to_black,
	black_to_white,
	yang_shi
} t_col_set_type;

struct s_col
{
	t_list	*palette;
	int		count;
};

struct s_complexe
{
	long double r;
	long double i;
};

struct s_case
{
	t_complexe	z;
	int			it;
};

typedef enum s_fract_type
{
	mandelbrot,
	julia,
	wtf
} t_fract_type;

struct s_key_stat
{
	int	k_a_left;
	int k_a_right;
	int k_a_up;
	int k_a_down;
	int k_zoom;
	int k_leftclick;
	int k_p;
	int k_m;
	int k_i;
	int k_shift;
	int k_shift2;
};

struct s_fractol
{
	t_fract_type	fract_type;
	t_key_stat		keys;
	t_case			**grille;
	t_complexe		c;
	t_complexe		mouse_c;
	t_col			col;
	t_list			**col_mod;
	t_col_set_type	color_set;
	int				col_panel_active;
	int				active_mouse;
	int				m_x;
	int				m_y;
	int				rw; //redraw
	int				rwa;
	int				pixel;
	void*			mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	short int		h_size;
	short int		v_size;
	long double		h_s;
	long double		v_s;
	int				precision;
	long double		pat;
};

//Complexe manipulation
void		add_complexe(t_complexe *z1, t_complexe z2, t_complexe z3);
void		sub_complexe(t_complexe *z, t_complexe z1, t_complexe z2);
void		sq_complexe(t_complexe *z);
void		mult_complexe(t_complexe *z, t_complexe z1, t_complexe z2);
void		set_complexe(t_complexe *z, long double reel, long double img);
long double mod_sq_complexe(t_complexe z);
long double	mod_complexe(t_complexe z);

//Error handler
void 		handle_error(char *err);

//Fractale calc and display functions
void 		display(t_fractol *fractale);
void 		reset_ligne(t_case *cases, int size);
void 		ft_mandelbrot(t_complexe *z, t_complexe z2);
int			calc_mandelbrot(t_complexe c, int it);
void		move_down(t_fractol *fractol, int y);
void		move_up(t_fractol *fractol, int y);
void		move_left(t_fractol *fractol, int speed);
void		move_right(t_fractol *fractol, int speed);
void		zoom_out(t_fractol *fractol, int x, int y);
void		zoom_in(t_fractol *fractol, int x, int y);
void		calc(t_fractol *fractol);
void 		ft_calc_mandelbrot(t_complexe *z, t_complexe c, int *it, int it_max);
void		next_mandelbrot(t_complexe *prec, t_complexe c);
void		init_grille(t_fractol *fractol);
void		add_precision(t_fractol *fractol);
void		sub_precision(t_fractol *fractol);
void		print_info(t_fractol *fractol);
int			create_trgb(t_color color);
void		change_color_aleatoire(t_fractol *fractol, t_color *col);
void		put_trgb_color(t_color *color, int trgb);
void		swap_color(t_fractol *fractol);
void		add_color(t_fractol *fractol);
void		active_color_panel(t_fractol *fractol);
void		panel_next(t_fractol *fractol);
void		create_panel(t_fractol *fractol);
void		switch_color(t_fractol *fractol);

//hooks functions

int ft_loop_hook(t_fractol *fractol);
int ft_key_hook(int keycode, t_fractol *fractol);
int ft_key_release(int keycode, t_fractol *fractol);
int ft_mouse_hook(int button, int x, int y, t_fractol *fractol);

#endif
