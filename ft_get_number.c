/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:43:36 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/12 21:07:24 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_number(int longa, char **argv, t_strc_gen *est)
{
	int	*a;
	int	num;
	int	aux;
	int	*auxy;
	int	x;
	int	y;
	int	z;
	int	countw;

	aux = 0;
	num = 0;
	x = 0;
	z = 0;
	y = 0;
	a = malloc(sizeof(int) * longa);
	while (x != longa)
	{
		num = ft_count_arg(argv[z + 1]);
		if (num < 0)
			est->error = 1;
		else if (num == 1)
		{
			aux = ft_atoi(argv[z + 1], est);
			a[x] = aux;
		}
		else
		{
			countw = ft_count_arg(argv[z + 1]);
			auxy = malloc(sizeof(int) * (countw));
			auxy = ft_split(argv[z + 1], *est);
			y = 0;
			countw = countw + x;
			while (x != countw)
			{
				a[x] = auxy[y];
				y++;
				x++;
			}
			x = countw - 1;
			free(auxy);
		}
		if (est->error != 0)
			return (0);
		x++;
		z++;
	}
	return (a);
}
