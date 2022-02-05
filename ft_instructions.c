/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:50:41 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/24 18:03:58 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* sa-sb-ss
    swap entre los dos primeros numeros
*/
struct s_strc	ft_swap_a(t_strc_gen estruc)
{
	int	num;

	printf("====SA====\n");
	num = estruc.a[0];
	estruc.a[0] = estruc.a[1];
	estruc.a[1] = num;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_swap_b(t_strc_gen estruc)
{
	int	num;

	num = estruc.b[0];
	estruc.b[0] = estruc.b[1];
	estruc.b[1] = num;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_swap(t_strc_gen estruc)
{
	int	num;

	num = estruc.a[0];
	estruc.a[0] = estruc.a[1];
	estruc.a[1] = num;
	num = estruc.b[0];
	estruc.b[0] = estruc.b[1];
	estruc.b[1] = num;
	estruc.count_mov++;
	return (estruc);
}

/* pa - pb
    pass el primer numero de una columna a la otra
*/

struct s_strc	ft_pass_a(t_strc_gen est)
{
	int	x;
	int	*auxa;
	int *auxb;

	x = 1;
	est.longb++;
	est.longa--;
	
	printf("====pb====\n");
	auxa = malloc (sizeof(int) * (est.longa));
	auxb = malloc (sizeof(int) * (est.longb));
	auxb[0] = est.a[0];
	
	if (est.longb == 1)
			est.b = malloc(sizeof(int) * 1);
	if (est.longb != 1)
	{
		
		while (x != (est.longb))
		{
			auxb[x] = est.b[x - 1];
			x++;
		}
	}
	x = 0;
	while (x != ((est.longa)))
	{
		auxa[x] = est.a[x + 1];
		x++;
	}
	free(est.a);
	free(est.b);
	est.b = auxb;
	est.a = auxa;
	est.count_mov++;
	return (est);
}

struct s_strc	ft_pass_b(t_strc_gen est)
{
	int	x;
	int	*auxa;
	int *auxb;

	x = 1;
	est.longa++;
	if (est.longb > 0)
		est.longb--;
	printf("====pa====\n");
	auxa = malloc (sizeof(int) * (est.longa));
	auxb = malloc (sizeof(int) * (est.longb));
	auxa[0] = est.b[0];
	if (est.longa != 1)
	{
		while (x != (est.longa))
		{
			auxa[x] = est.a[x - 1];
			x++;
		}
	}
	x = 0;
	while (x != ((est.longb)))
	{
		auxb[x] = est.b[x + 1];
		x++;
	}
	free(est.a);
	free(est.b);
	est.b = auxb;
	est.a = auxa;
	est.count_mov++;
	return (est);
}

/* ra - rb - rr
    rota todos los numeros hacia arriba todos los numeros, el primero sera el ultimo
*/

struct s_strc	ft_rot_a(t_strc_gen estruc)
{
	int	aux;
	int	x;

	printf("====ra====\n");
	x = 0;
	aux = estruc.a[0];
	while (x != (estruc.longa - 1))
	{
		estruc.a[x] = estruc.a[x + 1];
		x++;
	}
	estruc.a[x] = aux;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rot_b(t_strc_gen estruc)
{
	int	aux;
	int	x;

	printf("====ra====\n");
	x = 0;
	aux = estruc.b[0];
	while (x != (estruc.longb - 1))
	{
		estruc.b[x] = estruc.b[x + 1];
		x++;
	}
	estruc.b[x] = aux;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rot(t_strc_gen estruc)
{
	ft_rot_b(estruc);
	ft_rot_a(estruc);
	estruc.count_mov++;
	return (estruc);
}
/* rra - rrb - rrr
    rota todos los numeros hacia abajo todos los numeros, el ultimo sera el primero
*/

struct s_strc	ft_rrot_a(t_strc_gen estruc)
{
	int	aux;
	int	x;
	
	x = estruc.longa - 2;
	printf("====rrot A====\n");
	aux = estruc.a[estruc.longa - 1];
	while (x > (1-2))
	{
		estruc.a[x + 1] = estruc.a[x];
		x--;
	}
	estruc.a[0] = aux;
	estruc.count_mov++;

	/* MOSTRAR LAS DOS LISTAS*/
	/*	x = 0;
		while (x != estruc.longb)
		{
			printf(" \nb=%i= ", estruc.b[x]);
			x++;
		}
		x = 0;
		while (x != estruc.longa)
		{
			printf(" \na=%i= ", estruc.a[x]);
			x++;
		}
	*/	
	return (estruc);
}

struct s_strc	ft_rrot_b(t_strc_gen estruc)
{
	int	aux;
	int	x;
	
	x = estruc.longb - 2;
	printf("====rrot B====\n");
	aux = estruc.b[estruc.longb - 1];
	while (x > (1-2))
	{
		estruc.b[x + 1] = estruc.b[x];
		x--;
	}
	estruc.b[0] = aux;
	estruc.count_mov++;

	/* MOSTRAR LAS DOS LISTAS*/
		/*x = 0;
		while (x != estruc.longb)
		{
			printf(" \nb=%i= ", estruc.b[x]);
			x++;
		}
		x = 0;
		while (x != estruc.longa)
		{
			printf(" \na=%i= ", estruc.a[x]);
			x++;
		}
		*/
	return (estruc);
}

struct s_strc	ft_rrot(t_strc_gen estruc)
{
	ft_rrot_b(estruc);
	ft_rrot_a(estruc);
	estruc.count_mov++;
	return (estruc);
}
