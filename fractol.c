/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:47:02 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/06 14:26:21 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//http://warp.povusers.org/Mandelbrot/
//https://solarianprogrammer.com/2013/02/28/mandelbrot-set-cpp-11/
//https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

void	julia(t_cntrl *cntrl)
{
	int i = 0;
	int x = 0;
	int y = 0;
	//re = x axis, im = y axis

	double fact_re = (cntrl->max_re - cntrl->min_re) / (WID - 1);
	double fact_im = (cntrl->max_im - cntrl->min_im) / (HEI - 1);

	double c_re;
	double c_im;

	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	int iter = 150;

	while (y < HEI)
	{
		c_im = cntrl->max_im - y * fact_im;
		while (x < WID)
		{
			c_re = cntrl->min_re + x * fact_re;

			Z_re = c_re;
			Z_im = c_im;

			int is_inside = 1;
			while (i < iter)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					is_inside = 0;
					break ;
				}
				Z_im = 2 * Z_re * Z_im + 0.64543;
				Z_re = Z_re2 - Z_im2 - 0.1301;
				i++;
			}
			double t = (double)i / (double)iter;
			int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
			int green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			int blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
			cntrl->data[y * WID + x] = (red | green | blue) << 16;
			x++;
			i = 0;
		}
		x = 0;
		y++;
	}
}

void	mandelbrot(t_cntrl *cntrl)
{
	int i = 0;
	int x = 0;
	int y = 0;
	//re = x axis, im = y axis

	double fact_re = (cntrl->max_re - cntrl->min_re) / (WID - 1);
	double fact_im = (cntrl->max_im - cntrl->min_im) / (HEI - 1);

	double c_re;
	double c_im;

	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	int iter = 150;

	while (y < HEI)
	{
		c_im = cntrl->max_im - y * fact_im;
		while (x < WID)
		{
			c_re = cntrl->min_re + x * fact_re;

			Z_re = c_re;
			Z_im = c_im;

			int is_inside = 1;
			while (i < iter)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					is_inside = 0;
					break ;
				}
				Z_im = 2 * Z_re * Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
				i++;
			}
			double t = (double)i / (double)iter;
			int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
			int green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			int blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
			cntrl->data[y * WID + x] = (red | green | blue) << 8;
			x++;
			i = 0;
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
	if (argc != 2)
		exit (1);
	cntrl->fr_name = argv[1];
	default_settings(cntrl);
	if (ft_strcmp(cntrl->fr_name, "mandelbrot") == 0)
		mandelbrot(cntrl);
	if (ft_strcmp(cntrl->fr_name, "julia") == 0)
		julia(cntrl);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	key_mouse_control(cntrl);
	mlx_loop(cntrl->mlx);
	return (0);
}
