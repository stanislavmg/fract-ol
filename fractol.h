# ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define BLACK			0x000000
# define WHITE			0xFFFFFF

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_image
{
	void		*image;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_fractol
{
	char		*name;
	int			i;
	void		*mlx;
	void		*win;
	t_image		img;
	double		esc_v;
	double		shift_x;
	double		shift_y;
	double		factor;
	double		jx;
	double		jy;
}				t_fractol;

/*** INITIALIZATION ***/
void		fractal_init(t_fractol *fractal);
int			events_init(t_fractol *fractal);
/*** RENDER ***/
void		fractal_render(t_fractol *fractal);
void		draw_pixels(int x, int y, t_fractol *fractal);
void		put_pixel(int x, int y, t_image *img, int color);
int			julia_render(int x, int y, t_fractol *fractal);
int			mouse_handle(int keysym, int x, int y, t_fractol *fractal);
int			events_handle(int keysym, t_fractol *fractal);
/*** UTILS ***/
void		exit_fail(void);
t_complex	sum_cmplx(t_complex a, t_complex b);
t_complex	sqrt_cmplx(t_complex a);
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			fractal_exit(t_fractol *fractal);
double		atodbl(char *s);

# endif