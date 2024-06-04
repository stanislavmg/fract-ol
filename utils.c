#include "fractol.h"

t_complex	sum_cmplx(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}

t_complex	sqrt_cmplx(t_complex a)
{
	t_complex	res;

	res.re = (a.re * a.re) - (a.im * a.im);
	res.im = 2 * a.re * a.im;
	return (res);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

void	print_help(void)
{
	ft_putstr(HELP);
	exit(EXIT_FAILURE);
}

void	exit_fail(char *msg)
{
	ft_putstr(msg);
	exit(EXIT_FAILURE);
}
