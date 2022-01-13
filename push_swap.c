/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:47:48 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/13 19:54:29 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(void)
{
	int			x;
	t_strc_gen	estruc;

	x = 0;
	estruc.a = malloc (sizeof(int) * 6);
	estruc.b = malloc (sizeof(int) * 6);
	estruc.longa = 5;
	estruc.longb = 5;
	while (x != 5)
	{
		estruc.a[x] = x;
		estruc.b[x] = (x + 10);
		x++;
	}
	x = 0;
	/*while (x < 5)
	{
		printf(" <%i> ", estruc.a[x]);
		printf(" - %i - ", estruc.b[x]);
		x++;
	}*/
	estruc = ft_pass_b(estruc);
	x = 0;
	while (x < 4)
	{
		printf(" - %i- ", estruc.a[x]);
		x++;
	}
	x = 0;
	while (x < 6)
	{
		printf(" <%i> ", estruc.b[x]);
		x++;
	}
	return (0);
}
