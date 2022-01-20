/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:26 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/20 20:27:26 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_strc_gen est)
{
	if (est.a[1] == est.c[0])
	{
		if (est.a[2] == est.c[est.longa - 1])
			ft_swap_a(est);
		else
			ft_rot_a(est);
	}
	else if (est.a[1] == est.c[est.longa - 1])
	{
		if (est.a[0] == est.c[0])
		{
			ft_swap_a(est);
			ft_rot_a(est);
		}
		else
			ft_rrot_a(est);
	}
	else
	{
		ft_swap_a(est);
		ft_rrot_a(est);
	}
}

int	ft_check_lower(t_strc_gen est)
{
	int	x;

	x = 0;
	while (x < est.longa)
	{
		if (est.a[x] <= est.mid)
		{
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_get_count(t_strc_gen est)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	while (est.a[count1] != est.c[98])
		count1++;
	while (est.a[count2] != est.c[98])
		count2++;
	if (count1 > count2)
		return (count2);
	return (count1);
}

void	ft_one_hun(t_strc_gen est)
{
	int	x;
	int	aux;

	x = 2;
	aux = 0;
	while (est.longa != 2)
	{
		printf(" \nlargo de a: %i ", est.longa);
		if (est.longa % 2 == 0)
			aux += (est.longa / 2) - 1;
		else
			aux += (est.longa / 2);
		est.mid = est.c[aux];
		while (ft_check_lower(est) != 0 && est.longa != 2)
		{
			if (est.a[0] <= est.mid)
			{
				est = ft_pass_a(est);
			}
			else
			{
				est = ft_rot_a(est);
			}
			
		}
		/* ORDENAR LOS DOS QUE SE QUEDAN */
		if (est.a[0] > est.a[1])
			est = ft_swap_a(est);
		/* IR METIENDO UNO A UNO, OBSERVANDO SI SALE MEJOR HACER RRA O RA HASTA LLEGAR AL NUMERO*/
		aux = ft_get_count(est);
		printf(" \nmid: %i ", est.mid);
		//est.mid = est.c[aux-1];
		printf(" \nmid: %i ", est.mid);
		x = 0;
		while (x != est.longb)
		{
			printf(" \nb=%i= ", est.b[x]);
			x++;
		}
		x = 0;
		while (x != est.longa)
		{
			printf(" \na=%i= ", est.a[x]);
			x++;
		}
		
	}
	
}