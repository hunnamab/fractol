/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:49:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/04 15:53:46 by hunnamab         ###   ########.fr       */
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

# define WID	768
# define HEI	512

# define NAVY	0x25869D
# define BLACK  0x000000

typedef struct		s_cntrl
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	int32_t			end_color;
	int				x_pos;
	int				y_pos;
	int				scale;
}					t_cntrl;

void				default_settings(t_cntrl *cntrl);
int					key_mouse_control(t_cntrl *cntrl);

#endif
