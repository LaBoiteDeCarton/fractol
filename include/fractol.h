#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# define EXEC_PROTO "Usage : fractol <fractal-type> <precision:int> <screen-size:int,int>\n"
# define ERR_NOARG "Please enter some arguments\n"
# define ERR_MALLOC "We got some trouble to malloc capitain\n"
# define ERR_FRACTTYPE "Never heard about that fractal before\n"

typedef struct s_fractol		t_fractol;
typedef struct s_fract_screen	t_fract_screen;
typedef struct s_fract_ros		t_fract_ros;
typedef struct s_complexe 		t_complexe;

struct s_complexe
{
	long double reel;
	long double img;
};

typedef enum s_fract_type
{
	mandelbrot,
	julia,
} t_fract_type;

struct s_fract_screen
{
	short int h_size;
	short int v_size;
};

//note : pour faire un zoom il faut rependre la valeur du zoom en pourcentage sur les deux extermités selon la position de la souris.
//ex : souri position 20% de la gauche, donc on fait accroitre h_s de 20% du pas du zoom et decroitre h_e de 80% du pas de zoom.
// en même temps faire la meme chose avec v_s et v_e;

struct s_fract_ros
{
	long double v_s;
	long double v_e;
	long double h_s;
	long double h_e;
};

struct s_fractol
{
	void* mlx;
	void *win;
	short int precision;
	t_fract_type fract_type;
	t_fract_screen fract_screen;
	t_fract_ros fract_ros;
};

t_complexe *add_complexe(t_complexe *z1, t_complexe *z2);
t_complexe *sq_complexe(t_complexe *z);
t_complexe *create_complexe(long double reel, long double img);
long double mod_complexe(t_complexe *z);
void handle_error(char *err, t_fractol *fractol);
int ft_strisdigit(char *str)

#endif