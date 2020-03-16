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

t_cmplx	set_complex(double re, double im)
{
	t_cmplx complex;
	
	complex.re = re;
	complex.im = im;
	return (complex);
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
	cntrl->zoom = 1;
	cntrl->pos.re = 0.0;
	cntrl->pos.im = 0.0;
	cntrl->min.re = -2.0;
	cntrl->min.im = -2.0;
	cntrl->max.re = 2.0;
	cntrl->max.im = cntrl->min.im + (cntrl->max.re - cntrl->min.re) * HEI / WID;
	cntrl->k = set_complex(-0.74543, 0.11301);
}
