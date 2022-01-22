#ifndef FCT_H
# define FCT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define EXEC_PROTO "Usage : fct <fractal-type> <prec:unsigned int> <escape:unsigned int>"
# define ERR_NOARG "Please enter some arguments"
# define ERR_MALLOC "We got some trouble to malloc capitain"
# define ERR_FRACTTYPE "Never heard about that fractal before"
# define ERR_BAD2ARG "The precision should be only digits, like '42'"
# define ERR_TOOMUCHARG "Wait, you talk too much, tell me only the fractal name please"
# define ERR_UINT "numerical arguments type : <unsigned int>"
# define ERR_TOOBIG "numerical argument value is too big, we dont have eternity"
# define ERR_RANGE "be positive, numerical arguments should be positive too"

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
# define K_L 37
# define K_1 18
# define K_2 19
# define K_3 20
# define K_4 21
# define K_ESC 53
# define K_TAB 48
# define K_SHIFT 258
# define K_SHIFT2 257
# define K_SPACE 49

typedef struct s_fct			t_fct;
typedef struct s_complexe		t_complexe;
typedef struct s_key_stat		t_key_stat;
typedef struct s_col			t_col;
typedef struct s_color			t_color;
typedef struct s_case			t_case;

struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
};

typedef enum s_col_set_type
{
	white,
	white_to_black,
	black_to_white,
	yang_shi,
	medical,
	mindf
}	t_col_set_type;

struct	s_col
{
	t_list	*palette;
	t_list	*inside;
	int		count;
};

struct s_complexe
{
	long double	r;
	long double	i;
};

struct s_case
{
	t_complexe		z;
	unsigned int	it;
};

typedef enum s_fract_type
{
	mandelbrot,
	julia,
	mandelbrot2,
	mandelbrot3
}	t_fract_type;

struct s_key_stat
{
	int	k_a_left;
	int	k_a_right;
	int	k_a_up;
	int	k_a_down;
	int	k_zoom;
	int	k_leftclick;
	int	k_p;
	int	k_m;
	int	k_i;
	int	k_shift;
	int	k_shift2;
	int k_space;
	int k_t;
};

struct	s_fct
{
	t_fract_type	fract_type;
	t_key_stat		keys;
	t_case			**grille;
	t_complexe		c;
	t_complexe		mouse_c;
	t_col			col;
	t_color			inside;
	t_list			*col_mod;
	t_col_set_type	color_set;
	int				col_panel_active;
	int				active_mouse;
	int				m_x;
	int				m_y;
	int				rw; //redraw
	int				rwa;
	int				pixel;
	void			*mlx;
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
	unsigned int	precision;
	int				escape;
	int				lissage;
	long double		pat;
};

//Complexe manipulation
void		add_complexe(t_complexe *z1, t_complexe z2, t_complexe z3);
void		sub_complexe(t_complexe *z, t_complexe z1, t_complexe z2);
void		sq_complexe(t_complexe *z);
void		mult_complexe(t_complexe *z, t_complexe z1, t_complexe z2);
void		set_complexe(t_complexe *z, long double reel, long double img);
long double	mod_sq_complexe(t_complexe z);
long double	mod_complexe(t_complexe z);

//Error handler and free functions
void		handle_error(char *err, t_fct *fct);
void		freee(t_fct *fct);

//Grille manipulation

void		malloc_grille(t_fct *fct);
void		free_grille(t_fct *fct);
void		init_grille(t_fct *fct);
void		reset_ligne(t_case *cases, int size);

//ld functions

int			ft_strisld(char *str);
long double	ft_strtold(char *str);

//Fractale calc and display functions

void		display(t_fct *fractale);
void		reset_ligne(t_case *cases, int size);
void		ft_mandelbrot(t_complexe *z, t_complexe z2);
int			calc_mandelbrot(t_complexe c, int it);
void		calc(t_fct *fct);
void		ft_calc_mandelbrot(t_complexe *z, t_complexe c, unsigned int *it, t_fct *fct);
void		ft_calc_mandelbrot2(t_complexe *z, t_complexe c, unsigned int *it, t_fct *fct);
void		ft_calc_mandelbrot3(t_complexe *z, t_complexe c, unsigned int *it, t_fct *fct);
void		next_mandelbrot(t_complexe *prec, t_complexe c);
void		next_mandelbrot2(t_complexe *prec, t_complexe c);
void		next_mandelbrot3(t_complexe *prec, t_complexe c);
void		init_grille(t_fct *fct);
void		print_info(t_fct *fct);
void		calc_z_it_value(t_complexe *z, unsigned int *it, t_fct *fct);

//Precisions functions

void		add_precision(t_fct *fct);
void		sub_precision(t_fct *fct);

//Color related functions

int			create_trgb(int t, int r, int g, int b);
//void		change_color_aleatoire(t_fct *fct, t_color *col);
void		put_trgb_color(t_color *color, int r, int g, int b);
void		ft_findcolor_to_pixel(t_fct *fct, unsigned int it, t_complexe z);
void		detsroy_panel_color(t_fct *fct);

//Color panel related functions

void		create_panel(t_fct *fct);
void		switch_color(t_fct *fct);
void		active_color_panel(t_fct *fct);
void		panel_add_color(t_fct *fct);
void		panel_next(t_fct *fct);
void		panel_blue_down(t_fct *fct);
void		panel_blue_up(t_fct *fct);
void		panel_color_inside(t_fct *fct);

//Move/Zoom inside fractal funcitons

void		move_down(t_fct *fct, int y);
void		move_up(t_fct *fct, int y);
void		move_left(t_fct *fct, int speed);
void		move_right(t_fct *fct, int speed);
void		zoom_out(t_fct *fct, int x, int y);
void		zoom_in(t_fct *fct, int x, int y);

//hooks functions

int			ft_loop_hook(t_fct *fct);
int			ft_key_hook(int keycode, t_fct *fct);
int			ft_key_release(int keycode, t_fct *fct);
int			ft_mouse_hook(int button, int x, int y, t_fct *fct);

#endif
