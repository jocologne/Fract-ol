/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:10 by jcologne          #+#    #+#             */
/*   Updated: 2025/01/19 04:53:17 by jcologne         ###   ########.fr       */
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
# define W 400
# define H 400

typedef struct s_complex
{
	double x;
	double y;
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
	double	julia_x;
	double	julia_y;
}	t_fractal;

//render
void image_render(t_fractal *fractal);

//init
void	data_init(t_fractal *fractal);

//events
int	close_event(t_fractal *fractal);
int	key_event(int key, t_fractal *fractal);
int	mouse_event(int button, int x, int y, t_fractal *fractal);

//math
double convert(int pixel, double min, double max, int size);
t_complex sum(t_complex n1, t_complex n2);
t_complex	square(t_complex n);
double ft_atodbl(char *str);

#endif