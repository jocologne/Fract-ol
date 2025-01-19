/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:49:19 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/18 22:12:53 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_event(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_pointer);
	mlx_clear_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit (0);
}

int	key_event(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		close_event(fractal);
}
