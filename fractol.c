/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:47:02 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 14:13:49 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//http://warp.povusers.org/Mandelbrot/
//https://solarianprogrammer.com/2013/02/28/mandelbrot-set-cpp-11/
//https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

int		define_fractal(char *name, t_cntrl *cntrl)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		cntrl->fr_name = 'm';
		default_settings(cntrl);
		mandelbrot(cntrl);
	}
	else if (ft_strcmp(name, "julia") == 0)
	{
		cntrl->fr_name = 'j';
		default_settings(cntrl);
		julia(cntrl);
	}
	else if (ft_strcmp(name, "burning_ship") == 0)
	{
		cntrl->fr_name = 'b';
		default_settings(cntrl);
		burning_ship(cntrl);
	}
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cntrl	*cntrl;

	if (!(cntrl = (t_cntrl *)ft_memalloc(sizeof(t_cntrl))))
		return (0);
	if (argc != 2)
		error_handling(0);
	if (!(define_fractal(argv[1], cntrl)))
		error_handling(1);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	key_mouse_control(cntrl);
	mlx_loop(cntrl->mlx);
	return (0);
}
