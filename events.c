/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:49:19 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/28 15:03:59 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_event(t_fractal *fractal)
{
	if (fractal->img.img_pointer)
		mlx_destroy_image(fractal->mlx, fractal->img.img_pointer);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
}

int	key_event(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		close_event(fractal);
	if (key == XK_Right)
		fractal->shift_x += (0.1 * fractal->zoom);
	if (key == XK_Left)
		fractal->shift_x -= (0.1 * fractal->zoom);
	if (key == XK_Up)
		fractal->shift_y += (0.1 * fractal->zoom);
	if (key == XK_Down)
		fractal->shift_y -= (0.1 * fractal->zoom);
	image_render(fractal);
	return (0);
}

int	mouse_event(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 1.05;
	if (button == Button4)
		fractal->zoom *= 0.95;
	image_render(fractal);
	return (0);
}
