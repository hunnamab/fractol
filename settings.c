/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:34:38 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/13 17:46:18 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	default_settings(t_cntrl *cntrl)
{
	cntrl->mlx = mlx_init();
	cntrl->win = mlx_new_window(cntrl->mlx, WID, HEI, "fractol");
	cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
	cntrl->data = (int *)mlx_get_data_addr(cntrl->img, &cntrl->bpp, \
		&cntrl->size_line, &cntrl->endian);
	cntrl->iter = 100;
	cntrl->color = 0;
	cntrl->min_re = -1.5;
	cntrl->max_re = 1.5;
	cntrl->min_im = -1.7;
	cntrl->max_im = cntrl->min_im + (cntrl->max_re - cntrl->min_re) * HEI / WID;
	cntrl->k_im = 0.11301;
	cntrl->k_re = -0.74543;
}
