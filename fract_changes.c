/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:42:20 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 16:57:52 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    move(int key, t_cmplx *min, t_cmplx *max)
{
    if (key == 123)
	{
		min->re += 0.05;
		max->re += 0.05;
	}
	if (key == 126)
	{
		min->im -= 0.05;
		max->im -= 0.05;
	}
	if (key == 124)
	{
		min->re -= 0.05;
		max->re -= 0.05;
	}
	if (key == 125)
	{
		min->im += 0.05;
		max->im += 0.05;
	}
}

void	scroll(int button, t_cntrl *cntrl, double x, double y)
{
	if (button == 5) // 4
	{
		cntrl->zoom *= 0.9;
		cntrl->pos.re += (x / (WID / 2)) / cntrl->zoom;
	}
	if (button == 4) // 5
	{
		cntrl->zoom *= 1.1;
		cntrl->pos.im += (y / (HEI / 2)) / cntrl->zoom;
	}
}

void	julia_changes(t_cntrl *cntrl)
{
	if (cntrl->pr_y < cntrl->cur_y)
		cntrl->k.im += 0.0005;
	else if (cntrl->pr_y > cntrl->cur_y)
		cntrl->k.im -= 0.0005;
	if (cntrl->pr_x < cntrl->cur_x)
		cntrl->k.re += 0.0005;
	else if (cntrl->pr_x > cntrl->cur_x)
		cntrl->k.re -= 0.0005;
}
