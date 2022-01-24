/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:26 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/24 18:08:56 by ade-blas         ###   ########.fr       */
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

int	ft_get_count(t_strc_gen *est)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	/* MOSTRAR LAS DOS LISTAS*/
		x = 0;
		while (x != est->longb)
		{
			printf(" \nb=%i= ", est->b[x]);
			x++;
		}
		x = 0;
		while (x != est->longa)
		{
			printf(" \na=%i= ", est->a[x]);
			x++;
		}
	printf("\n  -- ENTRA A GET_COUNT---\n");
	printf("\n  NUMERO AUXILIAR : %i\n", est->aux);
	//if(est->b[count] != est->c[est->longc - est->aux])
	//printf("\n  NUMERO DE B : %i\n", est->b[count]);
	//printf("\n  NUMERO A BUSCAR  : %i\n", est->c[est->longc - est->aux]);

	while (est->b[count] != est->c[est->longc - est->aux])
	{
		printf("\n  NUMERO AUXILIAR : %i\n", est->aux);
		printf("\n  NUMERO a buscar : %i\n", est->c[est->longc - est->aux]);
		printf("\n  -- ENTRA A GET_COUNT while---\n");
		count++;
		//getchar();
	}
	printf("\n  NUMERO cont : %i\n", est->b[count]);
	printf("\n  NUMERO medio : %i\n", est->longb/2);
	if (count < (est->longb/2))
		return (1); 
	//si es menos de la mitad de la longitud lo mejor es rot_b
	printf("\n  -- SALE A GET_COUNT---\n");
	return (2);
}

struct s_strc	ft_one_hun(t_strc_gen est)
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
		
	}
	
	/* ORDENAR LOS DOS QUE SE QUEDAN */
		if (est.a[0] > est.a[1])
			est = ft_swap_a(est);
	/* IR METIENDO UNO A UNO, OBSERVANDO SI SALE MEJOR HACER RRA O RA HASTA LLEGAR AL NUMERO*/
	
	/* MOSTRAR LAS DOS LISTAS*/
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

		
	while (est.longa != est.longc)
	{
		printf("\n  --1 ENTRA A WHILE---\n");
		if (ft_get_count(&est) == 1)
		{
			printf("\n  --1 ENTRA A IF---\n");
			if (est.b[0] != est.c[est.longc - est.aux])
			{
				printf(" \nNUMERO a buscar =%i= ", est.c[est.longc - est.aux]);
				printf(" \nNUMERO a buscar =%i= ", est.b[0]);
				while (est.b[0] != est.c[est.longc - est.aux])
				{
					printf("\n  --2 a ENTRA A WHILEeeeee---\n");
					est = ft_rot_b(est);
				}
			}
		}
		else
		{
			printf("\n  --2 ENTRA A IF---\n");
			if (est.b[0] != est.c[est.longc - est.aux])
			{
				printf(" \nNUMERO a buscar =%i= ", est.c[est.longc - est.aux]);
				printf(" \nNUMERO a buscar =%i= ", est.b[0]);
				while (est.b[0] != est.c[est.longc - est.aux])
				{
					printf("\n  --2 b ENTRA A WHILE---\n");
					est = ft_rrot_b(est);
					printf(" \nNUMERO EST.B =%i= ", est.b[x]);
					printf(" \nNUMERO DE EST.C=%i= ", est.c[est.longc - est.aux]);
				}
			}
		}
		printf("\n  --SALE WHILE---\n");
		est.aux++;
		est = ft_pass_b(est);
		//getchar();
	}
	/* MOSTRAR LAS DOS LISTAS*/
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
		getchar();
	return (est);
		
}