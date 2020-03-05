/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:41:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/04 13:12:50 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_control(int key, t_cntrl *cntrl)
{
	if (key == 0xff1b) //53 or 0xff1b
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		key_mouse_control(t_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	return (0);
}
