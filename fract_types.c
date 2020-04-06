/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:01:47 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 17:17:51 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  fact_im(t_cntrl *cntrl)
{
	return ((cntrl->max.im - cntrl->min.im) / (HEI));
}

double  fact_re(t_cntrl *cntrl)
{
    return ((cntrl->max.re - cntrl->min.re) / (WID));
}

void	burning_ship(t_cntrl *cntrl)
{
	int i;
	int x;
	int y;
	//re = x axis, im = y axis

	double c_re;
	double c_im;

	double Z_re2;
	double Z_im2;

	y = 0;
	cntrl->min.re = ((cntrl->pos.re + (WID >> 1)) / (cntrl->zoom / 2)) / -2;
	cntrl->min.im = ((cntrl->pos.im + (HEI >> 1)) / (cntrl->zoom / 2)) / -2;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			c_re = x / cntrl->zoom + cntrl->min.re;
			c_im = y / cntrl->zoom + cntrl->min.im;

			cntrl->z = set_complex(cntrl->min.re + x * fact_re(cntrl), \
				cntrl->max.im - y * fact_im(cntrl));

			i = 0;
			while (i < cntrl->iter)
			{
				Z_re2 = cntrl->z.re * cntrl->z.re;
				Z_im2 = cntrl->z.im * cntrl->z.im;
				if (Z_re2 + Z_im2 > 4)
					break ;
				cntrl->z.im = 2 * fabs(cntrl->z.re * cntrl->z.im) - c_im;
				cntrl->z.re = Z_re2 - Z_im2 + c_re;
				i++;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
			x++;
		}
		y++;
	}
}

void	julia(t_cntrl *cntrl)
{
	int i;
	int x;
	int y;

	double Z_re2;
	double Z_im2;

	y = 0;
	cntrl->min.re = ((cntrl->pos.re + (WID >> 1)) / (cntrl->zoom / 2)) / -2;
	cntrl->min.im = ((cntrl->pos.im + (HEI >> 1)) / (cntrl->zoom / 2)) / -2;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			cntrl->z = set_complex(cntrl->min.re + x * fact_re(cntrl), \
				cntrl->max.im - y * fact_im(cntrl));

			i = 0;
			while (i < cntrl->iter)
			{
				Z_re2 = cntrl->z.re * cntrl->z.re;
				Z_im2 = cntrl->z.im * cntrl->z.im;
				if (Z_re2 + Z_im2 > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + (cntrl->k.im);
				cntrl->z.re = Z_re2 - Z_im2 + (cntrl->k.re);
				i++;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
			x++;
		}
		y++;
	}
}

void	mandelbrot(t_cntrl *cntrl)
{
	int i;
	int x;
	int y;
	//re = x axis, im = y axis

	double c_re;
	double c_im;

	double z_reb;
	double z_imb;

	y = 0;
	cntrl->min.re = ((cntrl->pos.re + (WID >> 1)) / (cntrl->zoom / 2)) / -2;
	cntrl->min.im = ((cntrl->pos.im + (HEI >> 1)) / (cntrl->zoom / 2)) / -2;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			c_re = x / cntrl->zoom + cntrl->min.re;
			c_im = y / cntrl->zoom + cntrl->min.im;

			cntrl->z = set_complex(c_re, c_im);
			//cntrl->z.re = 0;
			//cntrl->z.im = 0;

			i = 0;
			while (i < cntrl->iter)
			{
				z_reb = cntrl->z.re * cntrl->z.re;
				z_imb = cntrl->z.im * cntrl->z.im;
				if (z_reb + z_imb > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + c_im;
				cntrl->z.re = z_reb - z_imb + c_re;
				i++;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
			x++;
		}
		y++;
	}
}
