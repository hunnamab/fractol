/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:49:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 16:58:00 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include "mlx.h"
# include "libft.h"

# define WID	1500
# define HEI	1500

typedef	struct		s_cmplx
{
	double			re;
	double			im;
}					t_cmplx;

typedef struct		s_cntrl
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
	char			fr_name;
	int				iter;
	int				color;
	int				pr_x;
	int				pr_y;
	int				cur_x;
	int				cur_y;
	double			zoom;
	t_cmplx			min;
	t_cmplx			max;
	t_cmplx			k;
	t_cmplx			z;
	t_cmplx			pos;
}					t_cntrl;

void				error_handling(int i);
t_cmplx				set_complex(double re, double im);
void				mandelbrot(t_cntrl *cntrl);
void				julia(t_cntrl *cntrl);
void				burning_ship(t_cntrl *cntrl);
int					colors(int i, int iter, int color);
void				default_settings(t_cntrl *cntrl);
int					key_mouse_control(t_cntrl *cntrl);
void				julia_changes(t_cntrl *cntrl);
void				scroll(int button, t_cntrl *cntrl, double x, double y);
void    			move(int key, t_cmplx *min, t_cmplx *max);

#endif
