#include "fractol.h"

static double get_frct(char *s, int count)
{
	double	res;
	double	pow;
	int		i;
	
	i = 0;
	pow = 1;
	res = 0;
	while (*s)
	{
		i = 0;
		while ('0' == s[i])
		{
			if (!s[i + 1])
				*s = 0;
			i++;
		}
		if (!*s)
			break ;
		pow /= 10;
		res = res + (*s++ - 48) * pow;
		count++;
		if (count > DBL_DIG)
			exit_fail("Invalid arguments\n");
	}
	return (res);
}

static double get_num(char *s)
{
	long	integer_part;
	double	fraction_part;
	int		count;

	count = 0;
	integer_part = 0;
	while (*s != '.' && *s)
	{
		if (count > DBL_DIG)
			exit_fail("Invalid arguments\n");
		integer_part = (integer_part * 10) + (*s++ - 48);
		count++;
	}
	if ('.' == *s)
		++s;
	fraction_part = get_frct(s, count);
	return (integer_part + fraction_part);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit_fail("mlx connection init error\n");
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->win)
	{
		mlx_destroy_display(fractal->mlx);
		//free(fractal->mlx);
		exit_fail("mlx window init error\n");
	}
	fractal->img.image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.image)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		//free(fractal->mlx);
		exit_fail("mlx image init error\n");
	}
	fractal->img.data_addr = mlx_get_data_addr(fractal->img.image, &fractal->img.bits_per_pixel,
												&fractal->img.size_line, &fractal->img.endian);
	fractal->esc_v = 4.0;
	fractal->i = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->factor = 1.0;
}

double	ft_atodbl(char *s)
{
	int		sign;
	double	res;

	sign = 1;
	while (ft_isspace(*s))
		s++;
	if ('+' == *s)	
		s++;
	if ('-' == *s)
	{
		sign = -1;
		s++;
	}
	while ('0' == *s)
		s++;
	res = get_num(s) * sign;
	return (res);
}