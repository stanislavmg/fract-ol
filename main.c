#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractal;
	
	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) 
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.jx = atodbl(av[2]);
			fractal.jy = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	return (0);
}

void	exit_fail(void)
{
	perror("fractol");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit_fail();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit_fail();
	}
	fractal->img.image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.image)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit_fail();
	}
	fractal->img.data_addr = mlx_get_data_addr(fractal->img.image, &fractal->img.bits_per_pixel,
												&fractal->img.size_line, &fractal->img.endian);
	fractal->esc_v = 4.0;
	fractal->i = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->factor = 1.0;
	events_init(fractal);
}