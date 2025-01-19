/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:09:09 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/19 05:08:26 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	buffer_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_pointer + offset) = color;
}

static void	man_or_jul(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	pixel_color(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (convert(x, -2, 2, W) * fractal->zoom) + fractal->shift_x;
	z.y = (convert(y, -2, 2, H) * fractal->zoom) + fractal->shift_y;
	man_or_jul (&z, &c, fractal);
	while (i < fractal->image_definition)
	{
		z = sum(square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_distance)
		{
			color = 0x000000 + i * (0x001200 + (0x000012 *(1/fractal->zoom)));
			buffer_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	buffer_pixel(x, y, &fractal->img, 0x000000);
}

void	image_render(t_fractal *fractal)
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
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img.img_pointer, 0, 0);
}
