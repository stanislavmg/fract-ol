#include "fractol.h"

int	events_init(t_fractol *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, events_handle, fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, fractal_exit, fractal);
	mlx_hook(fractal->win, MotionNotify, PointerMotionMask, julia_render, fractal);
	return (0);
}

int	events_handle(int keysym, t_fractol *fractal)
{
	if(keysym == XK_Escape)
	 	fractal_exit(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->factor);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->factor);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->factor);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->factor);
	else if (keysym == XK_equal)
		fractal->i += 10;
	else if (keysym == XK_minus)
		fractal->i -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int keysym, int x, int y, t_fractol *fractal)
{
	(void)x;
	(void)y;
	if (keysym == Button4)
		fractal->factor *= 0.95;
	else if (keysym == Button5)
		fractal->factor *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	fractal_exit(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.image);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	//free(fractal->mlx);
	exit(EXIT_SUCCESS);
}