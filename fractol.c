/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:47:02 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/04 16:03:58 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//http://warp.povusers.org/Mandelbrot/
//https://github.com/VBrazhnik/Fract-ol/wiki/
//https://solarianprogrammer.com/2013/02/28/mandelbrot-set-cpp-11/
//https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

void	draw_fractal(t_cntrl *cntrl)
{
	int x = 0;
	int y = 0;
	//re = x axis, im = y axis
	double min_re = -2.0;
	double max_re = 2.0;
	double min_im = -2.0;
	double max_im = min_im + (max_re - min_re) * HEI / WID;

	int iter = 50;

	while (y < HEI)
	{
		while (x < WID)
		{
			x++;
		}
		x = 0;
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_cntrl	*cntrl;

	if (!(cntrl = (t_cntrl *)ft_memalloc(sizeof(t_cntrl))))
		return (0);
	default_settings(cntrl);
	draw_fractal(cntrl);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	key_mouse_control(cntrl);
	mlx_loop(cntrl->mlx);
	return (0);
}
