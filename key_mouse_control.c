/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:41:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/13 17:49:49 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_changes(int key, t_cntrl *cntrl)
{
	if (key == 123 || key == 124 || key == 125 || key == 126 || \
			key == 27 || key == 24 || key == 18 || key == 19 || key == 20)
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
		if (key == 27)
			cntrl->iter -= 10;
		if (key == 24)
			cntrl->iter += 10;
		if (key == 18)
			cntrl->color = 0;
		if (key == 19)
			cntrl->color = 1;
		if (key == 20)
			cntrl->color = 2;
	}
}

int		key_control(int key, t_cntrl *cntrl)
{
	if (key == 53) //53 or 0xff1b
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 123 || key == 124 || key == 125 || key == 126 || \
			key == 27 || key == 24 || key == 18 || key == 19 || key == 20) // key == 0xff51 || key == 0xff52 || key == 0xff53 || key == 0xff54
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
		if (cntrl->fr_name == 'b')
			burning_ship(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	}
	return (0);
}

void	julia_changes(t_cntrl *cntrl)
{
	if (cntrl->pr_y < cntrl->cur_y)
		cntrl->k_im += 0.0005;
	else if (cntrl->pr_y > cntrl->cur_y)
		cntrl->k_im -= 0.0005;
	if (cntrl->pr_x < cntrl->cur_x)
		cntrl->k_re += 0.0005;
	else if (cntrl->pr_x > cntrl->cur_x)
		cntrl->k_re -= 0.0005;
}

int		mouse_move(int x, int y, t_cntrl *cntrl)
{
	if (cntrl->fr_name == 'j')
	{
		cntrl->pr_x = cntrl->cur_x;
		cntrl->pr_y = cntrl->cur_y;
		cntrl->cur_x = x;
		cntrl->cur_y = y;
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		julia_changes(cntrl);
		if (cntrl->fr_name == 'j')
			julia(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	}
	return (0);
}

void	scroll(int button, t_cntrl *cntrl)
{
	if (button == 5) // 4
	{
		cntrl->min_re *= 0.9;
		cntrl->max_re *= 0.9;
		cntrl->min_im *= 0.9;
		cntrl->max_im *= 0.9;
	}
	if (button == 4) // 5
	{
		cntrl->min_re *= 1.1;
		cntrl->max_re *= 1.1;
		cntrl->min_im *= 1.1;
		cntrl->max_im *= 1.1;
	}
}

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
	if (cntrl->fr_name == 'b')
		burning_ship(cntrl);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	return (0);
}

int		key_mouse_control(t_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	mlx_hook(cntrl->win, 6, (1L << 6), mouse_move, cntrl);
	mlx_hook(cntrl->win, 4, (1L << 2), mouse_press, cntrl);
	return (0);
}
