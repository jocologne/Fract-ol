/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:09:09 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/18 23:47:03 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void buffer_pixel(int x, int y, t_img *img, int color)
{
	int	offset;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_pointer + offset) = color;
}

static void man_or_jul(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_real;
		c->img = fractal->julia_img;
	}
	else
	{
		c->real = z->real;
		c->img = z->img;
	}
}

static void pixel_color(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = convert(x, -2, 2, W);
	z.img = convert(y, -2, 2, H);
	man_or_jul (&z, &c, fractal);
	while (i < fractal->image_definition)
	{
		z = sum(square(z), c);
		if ((z.real * z.real) + (z.img * z.img) > fractal->escape_distance)
		{
			color = fractal->palette[i % fractal->palette_size];
			buffer_pixel(x, y, &fractal->img, color);
			return;
		}
		i++;
	}
	buffer_pixel(x, y, &fractal->img, 0);
}

void image_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pixel_color(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx,
									fractal->window,
									fractal->img.img_pointer,
									0,0);
}
