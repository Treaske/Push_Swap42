/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:26 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/19 18:09:13 by ade-blas         ###   ########.fr       */
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
		if (est.a[x] < est.mid)
		{
			return (1);
		}
		x++;
	}
	return (0);
}
void	ft_one_hun(t_strc_gen est)
{
	int	x;

	x = 0;
	printf(" ..%i..\n", est.longa);
	printf(",,%i,,\n", est.longb);
	printf(" ..%i..\n", est.mid);
	while (ft_check_lower(est) != 0)
	{
		printf(" .....%i.......\n", est.a[0]);
		if (est.a[0] < est.mid)
		{
			printf(" .....%i.......\n", est.a[0]);
			ft_pass_a(est);
			//printf(" &%i&\n", est.b[0]);
		}
		else
		{
			printf(" .%i.\n", est.a[0]);
			ft_rot_a(est);
			printf(" ,%i,\n", est.a[0]);
			
		}
	}
	x = 0;
	while (x != est.longb)
	{
		printf(" ==%i== ", est.b[x]);
		x++;
	}
	x = 0;
	while (x != est.longb)
	{
		printf(" --%i-- ", est.b[x]);
		x++;
	}
}