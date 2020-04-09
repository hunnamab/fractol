/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:34:38 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 17:07:54 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_re_im(t_cntrl *cntrl, int x, int y)
{
	if (cntrl->fr_name == 'm' || cntrl->fr_name == 'b')
	{
		cntrl->c.re = x / cntrl->zoom + cntrl->min.re;
		cntrl->c.im = y / cntrl->zoom + cntrl->min.im;
		cntrl->z.im = 0;
		cntrl->z.re = 0;
	}
	if (cntrl->fr_name == 'j')
	{
		cntrl->z.im = y / cntrl->zoom + cntrl->min.im;
		cntrl->z.re = x / cntrl->zoom + cntrl->min.re;
	}
}

void	set_minimum(t_cntrl *cntrl)
{
	cntrl->min.re = ((cntrl->pos.re + (WID >> 1)) / (cntrl->zoom / 2)) / -2;
	cntrl->min.im = ((cntrl->pos.im + (HEI >> 1)) / (cntrl->zoom / 2)) / -2;
}

void	fractals_settings(t_cntrl *cntrl)
{
	if (cntrl->fr_name == 'm')
	{
		cntrl->zoom = 280;
		cntrl->pos.re = 160.0;
		cntrl->pos.im = 0.0;
	}
	if (cntrl->fr_name == 'j')
	{
		cntrl->zoom = 240;
		cntrl->pos.re = 0.0;
		cntrl->pos.im = 0.0;
	}
	if (cntrl->fr_name == 'b')
	{
		cntrl->zoom = 240;
		cntrl->pos.re = 100.0;
		cntrl->pos.im = 100.0;
	}
}

void	default_settings(t_cntrl *cntrl)
{
	cntrl->mlx = mlx_init();
	cntrl->win = mlx_new_window(cntrl->mlx, WID, HEI, "fractol");
	cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
	cntrl->data = (int *)mlx_get_data_addr(cntrl->img, &cntrl->bpp, \
		&cntrl->size_line, &cntrl->endian);
	cntrl->iter = 100;
	cntrl->color = 0;
	cntrl->menu = 1;
	fractals_settings(cntrl);
	cntrl->k.re = -0.74543;
	cntrl->k.im = 0.11301;
}
