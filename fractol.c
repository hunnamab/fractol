/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:47:02 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/06 15:20:47 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//http://warp.povusers.org/Mandelbrot/
//https://solarianprogrammer.com/2013/02/28/mandelbrot-set-cpp-11/
//https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

int		main(int argc, char **argv)
{
	t_cntrl	*cntrl;

	if (!(cntrl = (t_cntrl *)ft_memalloc(sizeof(t_cntrl))))
		return (0);
	if (argc != 2)
		exit (1);
	default_settings(cntrl);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		cntrl->fr_name = 'm';
		mandelbrot(cntrl);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		cntrl->fr_name = 'j';
		julia(cntrl);
	}
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	key_mouse_control(cntrl);
	mlx_loop(cntrl->mlx);
	return (0);
}
