/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:02:07 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/12 17:36:41 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc	ft_three(t_strc_gen est)
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
	return (est);
}
