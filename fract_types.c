/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:01:47 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/13 17:46:45 by hunnamab         ###   ########.fr       */
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

void	burning_ship(t_cntrl *cntrl)
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

	while (y < HEI)
	{
		c_im = cntrl->max_im - y * fact_im(cntrl);
		while (x < WID)
		{
			c_re = cntrl->min_re + x * fact_re(cntrl);

			Z_re = c_re;
			Z_im = c_im;

			int is_inside = 1;
			while (i < cntrl->iter)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					is_inside = 0;
					break ;
				}
				Z_im = 2 * fabs(Z_re * Z_im) - c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
				i++;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
			x++;
			i = 0;
		}
		x = 0;
		y++;
	}
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

	while (y < HEI)
	{
		while (x < WID)
		{
			Z_im = cntrl->max_im - y * fact_im(cntrl);
			Z_re = cntrl->min_re + x * fact_re(cntrl);

			int is_inside = 1;
			while (i < cntrl->iter)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					is_inside = 0;
					break ;
				}
				Z_im = 2 * Z_re * Z_im + (cntrl->k_im);
				Z_re = Z_re2 - Z_im2 + (cntrl->k_re);
				i++;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
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

	while (y < HEI)
	{
		c_im = cntrl->max_im - y * fact_im(cntrl);
		while (x < WID)
		{
			c_re = cntrl->min_re + x * fact_re(cntrl);

			Z_re = c_re;
			Z_im = c_im;

			int is_inside = 1;
			while (i < cntrl->iter)
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
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
			x++;
			i = 0;
		}
		x = 0;
		y++;
	}
}
