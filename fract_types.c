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

void	burning_ship(t_cntrl *cntrl)
{
	int i;
	int x;
	int y;
	double z_reb;
	double z_imb;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				z_reb = cntrl->z.re * cntrl->z.re;
				z_imb = cntrl->z.im * cntrl->z.im;
				if (z_reb + z_imb > 4)
					break ;
				cntrl->z.im = 2 * fabs(cntrl->z.re * cntrl->z.im) + cntrl->c.im;
				cntrl->z.re = z_reb - z_imb + cntrl->c.re;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

void	julia(t_cntrl *cntrl)
{
	int i;
	int x;
	int y;
	double z_reb;
	double z_imb;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				z_reb = cntrl->z.re * cntrl->z.re;
				z_imb = cntrl->z.im * cntrl->z.im;
				if (z_reb + z_imb > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + (cntrl->k.im);
				cntrl->z.re = z_reb - z_imb + (cntrl->k.re);
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

void	mandelbrot(t_cntrl *cntrl)
{
	int i;
	int x;
	int y;
	double z_reb;
	double z_imb;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				z_reb = cntrl->z.re * cntrl->z.re;
				z_imb = cntrl->z.im * cntrl->z.im;
				if (z_reb + z_imb > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + cntrl->c.im;
				cntrl->z.re = z_reb - z_imb + cntrl->c.re;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

void	draw_fractal(t_cntrl *cntrl)
{
	set_minimum(cntrl);
	if (cntrl->fr_name == 'm')
		mandelbrot(cntrl);
	if (cntrl->fr_name == 'j')
		julia(cntrl);
	if (cntrl->fr_name == 'b')
		burning_ship(cntrl);
}
