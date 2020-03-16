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
	cntrl->min.re = (cntrl->min.re / cntrl->zoom) + cntrl->pos.re;
	cntrl->max.re = (cntrl->max.re / cntrl->zoom) + cntrl->pos.re;
	cntrl->min.im = (cntrl->min.im / cntrl->zoom) + cntrl->pos.im;
	cntrl->max.im = (cntrl->max.im / cntrl->zoom) + cntrl->pos.im;
	while (y < HEI)
	{
		c_im = cntrl->max.im - y * fact_im(cntrl);
		x = 0;
		while (x < WID)
		{
			c_re = cntrl->min.re + x * fact_re(cntrl);

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
	cntrl->min.re = (cntrl->min.re / cntrl->zoom) + cntrl->pos.re;
	cntrl->max.re = (cntrl->max.re / cntrl->zoom) + cntrl->pos.re;
	cntrl->min.im = (cntrl->min.im / cntrl->zoom) + cntrl->pos.im;
	cntrl->max.im = (cntrl->max.im / cntrl->zoom) + cntrl->pos.im;
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

	double Z_re2;
	double Z_im2;

	y = 0;
	
	while (y < HEI)
	{
		c_im = cntrl->max.im - y * fact_im(cntrl);
		x = 0;
		while (x < WID)
		{
			/*cntrl->min.re = (cntrl->min.re / cntrl->zoom) + cntrl->pos.re;
			cntrl->max.re = (cntrl->max.re / cntrl->zoom) + cntrl->pos.re;
			cntrl->min.im = (cntrl->min.im / cntrl->zoom) + cntrl->pos.im;
			cntrl->max.im = (cntrl->max.im / cntrl->zoom) + cntrl->pos.im;*/
			c_re = cntrl->min.re + x * fact_re(cntrl);
			
			cntrl->z = set_complex(c_re, c_im);

			i = 0;
			while (i < cntrl->iter)
			{
				Z_re2 = cntrl->z.re * cntrl->z.re;
				Z_im2 = cntrl->z.im * cntrl->z.im;
				if (Z_re2 + Z_im2 > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + c_im;
				cntrl->z.re = Z_re2 - Z_im2 + c_re;
				i++;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
			x++;
		}
		y++;
	}
}
