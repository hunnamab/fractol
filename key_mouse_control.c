/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:41:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/06 19:22:22 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll(int button, t_cntrl *cntrl)
{
	if (button == 4) // 4
	{
		cntrl->min_re *= 0.9;
		cntrl->max_re *= 0.9;
		cntrl->min_im *= 0.9;
		cntrl->max_im *= 0.9;
	}
	if (button == 5) // 5
	{
		cntrl->min_re *= 1.1;
		cntrl->max_re *= 1.1;
		cntrl->min_im *= 1.1;
		cntrl->max_im *= 1.1;
	}
}

void	img_changes(int key, t_cntrl *cntrl)
{
	if (key == 0xff51 || key == 0xff52 || key == 0xff53 || key == 0xff54)
	{
		if (key == 0xff51)
		{
			cntrl->min_re += 0.05;
			cntrl->max_re += 0.05;
		}
		if (key == 0xff52)
		{
			cntrl->min_im -= 0.05;
			cntrl->max_im -= 0.05;
		}
		if (key == 0xff53)
		{
			cntrl->min_re -= 0.05;
			cntrl->max_re -= 0.05;
		}
		if (key == 0xff54)
		{
			cntrl->min_im += 0.05;
			cntrl->max_im += 0.05;
		}
	}
}

int		key_control(int key, t_cntrl *cntrl)
{
	if (key == 0xff1b) //53 or 0xff1b
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 0xff51 || key == 0xff52 || key == 0xff53 || key == 0xff54) // 123 124 125 126
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		img_changes(key, cntrl);
		if (cntrl->fr_name == 'm')
			mandelbrot(cntrl);
		if (cntrl->fr_name == 'j')
			julia(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	}
	return (0);
}

/*int		mouse_move(int x, int y, t_cntrl *cntrl)
{
	if (cntrl->img)
		mlx_destroy_image(cntrl->mlx, cntrl->img);
	cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
	cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
		&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	return (0);
}*/

int		mouse_press(int button, int x, int y, t_cntrl *cntrl)
{
	if (cntrl->img)
		mlx_destroy_image(cntrl->mlx, cntrl->img);
	cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
	cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
		&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
	scroll(button, cntrl);
	if (cntrl->fr_name == 'm')
		mandelbrot(cntrl);
	if (cntrl->fr_name == 'j')
		julia(cntrl);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	return (0);
}

int		key_mouse_control(t_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	//mlx_hook(cntrl->win, 6, (1L << 0), mouse_move, cntrl);
	mlx_hook(cntrl->win, 4, (1L << 2), mouse_press, cntrl);
	return (0);
}
