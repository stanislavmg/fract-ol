#include "fractol.h"

int	julia_render(int x, int y, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->jx = (map(x, -2, +2, 0, WIDTH) * fractal->factor) + fractal->shift_x;
		fractal->jy = (map(y, +2, -2, 0, HEIGHT) * fractal->factor) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
void	draw_pixels(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.re = (map(x, -2, +2, 0, WIDTH) * fractal->factor) + fractal->shift_x;
	z.im = (map(y, +2, -2, 0, HEIGHT) * fractal->factor) + fractal->shift_y;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c.re = fractal->jx;
		c.im = fractal->jy;
	}
	else
	{
		c.re = z.re;
		c.im = z.im;
	}
	// z = z^2 + c
	while (i < fractal->i)
	{
		z = sum_cmplx(sqrt_cmplx(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->esc_v)
		{
			color = map(i, BLACK, WHITE, 0, fractal->i);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, BLACK);
}

void	put_pixel(int x, int y, t_image *img, int color)
{
	int	off;

	off = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->data_addr + off) = color;
}

void	fractal_render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			draw_pixels(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.image, 0, 0);
}