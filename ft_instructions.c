/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:50:41 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/13 19:59:47 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa-sb-ss
    swap entre los dos primeros numeros
*/
struct s_strc	ft_swap_a(t_strc_gen estruc)
{
	int	num;

	num = estruc.a[0];
	estruc.a[0] = estruc.a[1];
	estruc.a[1] = num;
	return (estruc);
}

struct s_strc	ft_swap_b(t_strc_gen estruc)
{
	int	num;

	num = estruc.b[0];
	estruc.b[0] = estruc.b[1];
	estruc.b[1] = num;
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
	return (estruc);
}

/* pa - pb
    pass el primer numero de una columna a la otra
*/

struct s_strc	ft_pass_a(t_strc_gen estruc)
{
	int	x;
	int	*auxa;
	int *auxb;

	x = 1;
	auxa = malloc (sizeof(int) * (estruc.longa) - 1);
	auxb = malloc (sizeof(int) * (estruc.longb) + 1);
	auxb[0] = estruc.a[0];
	while (x != (estruc.longb) + 1)
	{
		auxb[x] = estruc.b[x - 1];
		x++;
	}
	x = 0;
	while (x != ((estruc.longa) - 1))
	{
		auxa[x] = estruc.a[x + 1];
		x++;
	}
	free(estruc.a);
	free(estruc.b);
	estruc.b = auxb;
	estruc.a = auxa;
	return (estruc);
}

struct s_strc	ft_pass_b(t_strc_gen estruc)
{
	int	x;
	int	*auxa;
	int *auxb;

	x = 1;
	auxb = malloc (sizeof(int) * (estruc.longb) - 1);
	auxa = malloc (sizeof(int) * (estruc.longa) + 1);
	auxa[0] = estruc.b[0];
	while (x != (estruc.longa) + 1)
	{
		auxa[x] = estruc.a[x - 1];
		x++;
	}
	x = 0;
	while (x != ((estruc.longb) - 1))
	{
		auxb[x] = estruc.b[x + 1];
		x++;
	}
	free(estruc.a);
	free(estruc.b);
	estruc.b = auxb;
	estruc.a = auxa;
	return (estruc);
}

/* ra - rb - rr
    rota todos los numeros hacia arriba todos los numeros, el primero sera el ultimo
*/

struct s_strc	ft_rot_a(t_strc_gen estruc)
{
	int	aux;
	int	num;
	int	x;

	num = estruc.longa;
	x = 0;
	aux = estruc.a[0];
	estruc.a[num] = aux;
	while (x != num)
	{
		aux = estruc.a[x];
		estruc.a[x] = estruc.a[x + 1];
		x++;
	}
	return (estruc);
}

struct s_strc	ft_rot_b(t_strc_gen estruc)
{
	int	aux;
	int	num;
	int	x;

	num = estruc.longb;
	x = 0;
	aux = estruc.b[0];
	estruc.b[num] = aux;
	while(x != num)
	{
		aux = estruc.b[x];
		estruc.b[x] = estruc.b[x + 1];
		x++;
	}
	
	return (estruc);
}

struct s_strc	ft_rot(t_strc_gen estruc)
{
	ft_rot_b(estruc);
	ft_rot_a(estruc);
	return (estruc);
}
/* rra - rrb - rrr
    rota todos los numeros hacia abajo todos los numeros, el ultimo sera el primero
*/

struct s_strc	ft_rrot_a(t_strc_gen estruc)
{
	int	aux;
	int	num;
	int aux2;
	int	x;

	num = estruc.longa;
	x = 0;
	aux2 = estruc.a[num-1];
	while(num != x)
	{
		aux = estruc.a[num];
		estruc.a[num] =  estruc.a[num - 1];
		num--;
	}
	estruc.a[0] = aux2;
	return (estruc);
}

struct s_strc	ft_rrot_b(t_strc_gen estruc)
{
	int	aux;
	int aux2;
	int	num;
	int	x;

	num = estruc.longb;
	x = 0;
	aux2 = estruc.b[num-1];
	while (num != x)
	{
		aux = estruc.b[num];
		estruc.b[num] = estruc.b[num - 1];
		num--;
	}
	estruc.b[0] = aux2;
	return (estruc);
}

struct s_strc	ft_rrot(t_strc_gen estruc)
{
	ft_rrot_b(estruc);
	ft_rrot_a(estruc);
	return (estruc);
}