/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:41:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/06 13:32:05 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_changes(int key, t_cntrl *cntrl)
{
	/*if (key == 24 || key == 27)
	{
		if (key == 27)
		{
			cntrl->min_re -= 0.1;
			//cntrl->max_re += 0.1;
			cntrl->min_im -= 0.1;
			//cntrl->max_im += 0.1;
		}
		if (key == 24)
		{
			cntrl->min_re += 0.1;
			//cntrl->max_re -= 0.1;
			cntrl->min_im += 0.1;
			//cntrl->max_im -= 0.1;
		}
	}*/
	if (key == 123 || key == 126 || key == 124 || key == 125)
	{
		if (key == 123)
		{
			cntrl->min_re += 0.05;
			cntrl->max_re += 0.05;
		}
		if (key == 126)
		{
			cntrl->min_im -= 0.05;
			cntrl->max_im -= 0.05;
		}
		if (key == 124)
		{
			cntrl->min_re -= 0.05;
			cntrl->max_re -= 0.05;
		}
		if (key == 125)
		{
			cntrl->min_im += 0.05;
			cntrl->max_im += 0.05;
		}
	}
}

int		key_control(int key, t_cntrl *cntrl)
{
	if (key == 53) //53 or 0xff1b
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 24 || key == 27 || key == 123 || key == 126 || key == 124 || key == 125)
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		img_changes(key, cntrl);
		mandelbrot(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	}
	return (0);
}

int		key_mouse_control(t_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	return (0);
}
