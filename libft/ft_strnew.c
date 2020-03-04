/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:21:21 by pmetron           #+#    #+#             */
/*   Updated: 2019/10/18 20:56:11 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *mem;

	if (NULL == (mem = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero((void *)mem, (size + 1));
	return (mem);
}
