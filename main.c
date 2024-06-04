#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 11))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			if (check_arg(av[2]) || check_arg(av[3]))
			{
				ft_putstr("Invalid argument\n");
				exit(EXIT_FAILURE);
			}
			fractal.jx = ft_atodbl(av[2]);
			fractal.jy = ft_atodbl(av[3]);
			printf("%lf\n", fractal.jx);
		}
		fractal_init(&fractal);
		events_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		print_help();
	return (0);
}
