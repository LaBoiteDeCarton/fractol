#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define EXEC_PROTO "Usage : fractol <fractal-type> <precision:int> <screen-size:int,int>\n"
# define ERR_NOARG "Please enter some arguments\n"
# define ERR_MALLOC "We got some trouble to malloc capitain\n"
# define ERR_FRACTTYPE "Never heard about that fractal before\n"
# define ERR_BAD2ARG "The precision should be only digits, like '42'\n"

typedef struct s_fractol		t_fractol;
typedef struct s_complexe 		t_complexe;
typedef struct s_color			t_color;

struct s_color
{
	int r;
	int g;
	int b;
};

struct s_complexe
{
	long double r;
	long double i;
};

typedef enum s_fract_type
{
	mandelbrot,
	julia,
} t_fract_type;

struct s_fractol
{
	t_fract_type	fract_type;
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
	long double		h_e;
	long double		v_e;
	short int		precision;
	long double		pat;
};

//Complexe manipulation
void		add_complexe(t_complexe *z1, t_complexe z2, t_complexe z3);
void		sq_complexe(t_complexe *z);
void		set_complexe(t_complexe *z, long double reel, long double img);
long double	mod_complexe(t_complexe z);

//Error handler
void 		handle_error(char *err);

//Fractale calc and display functions
void 		display(t_fractol *fractale);
void 		ft_mandelbrot(t_complexe *z, t_complexe z2);
int			calc_mandelbrot(t_complexe c, int it);
void		move_to_down(t_fractol *fractol);

#endif