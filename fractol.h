/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:10 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/18 23:48:21 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <X11/Xlib.h>
#include <X11/keysym.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"

//Window
# define W 800
# define H 800

//Palette
# define C1 = 0x0000FF
# define C2 = 0x00FF00
# define C3 = 0xFF0000
# define C4 = 0xFFFF00
# define C5 = 0xFF00FF

typedef struct s_complex
{
	double real;
	double img;
}	t_complex;

typedef struct s_img
{
	void	*img_pointer;
	char	*pixel_pointer;
	int	bpp;
	int	endian;
	int	line_len;
}	t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*window;
	t_img		img;
	double	escape_distance;
	int		image_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_real;
	double	julia_img;
	int		*palette;
	int		palette_size;
}	t_fractal;

//render
void image_render(t_fractal *fractal);

//init
void	data_init(t_fractal *fractal);

//events
int	close_event(t_fractal *fractal);
int	key_event(int key, t_fractal *fractal);

//math
double convert(int pixel, double min, double max, int size);
t_complex sum(t_complex n1, t_complex n2);
t_complex	square(t_complex n);

#endif