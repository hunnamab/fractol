/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:01:47 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/06 17:44:15 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  fact_im(t_cntrl *cntrl)
{
	return ((cntrl->max_im - cntrl->min_im) / (HEI - 1));
}

double  fact_re(t_cntrl *cntrl)
{
    return ((cntrl->max_re - cntrl->min_re) / (WID - 1));
}

void	julia(t_cntrl *cntrl)
{
	int i = 0;
	int x = 0;
	int y = 0;
	//re = x axis, im = y axis

	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;
    double Z_n;
    double t;

	int iter = 150;

	while (y < HEI)
	{
		while (x < WID)
		{
            Z_im = cntrl->max_im - y * fact_im(cntrl);
			Z_re = cntrl->min_re + x * fact_re(cntrl);

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
				Z_im = 2 * Z_re * Z_im + 0.11301;
				Z_re = Z_re2 - Z_im2 + (-0.74543);
				i++;
			}
            if (i < iter)
            {
                Z_n = sqrt(Z_re * Z_re + Z_im * Z_im);
                t = iter + 1 - (log(2) / Z_n) / log(2);
                int red = (sin(0.016 * t + 4) * 230 + 25);
                int green = (sin(0.013 * t + 2) * 230 + 25);
                int blue = (sin(0.01 * t + 1) * 230 + 25);
                green = green >> 8;
                red = red >> 16;
                blue = blue & 255;
                green = green & 130560;
                red = red & 66846720;
                cntrl->data[y * WID + x] = red | green | blue | 255;
            }
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

	double c_re;
	double c_im;

	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	int iter = 150;

	while (y < HEI)
	{
		c_im = cntrl->max_im - y * fact_im(cntrl);
		while (x < WID)
		{
			c_re = cntrl->min_re + x * fact_re(cntrl);

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
