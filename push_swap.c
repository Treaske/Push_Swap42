/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:47:48 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/17 20:09:31 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	cont;

	num = 0;
	sign = 1;
	cont = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	return (num * sign);
}

int *ft_get_number(int len, char **argv)
{
	int	*a;
	int aux;
	int	x;

	aux = 0;
	x = 0;
	a = malloc(sizeof(int) * len + 1);
	a[len] = 0;
	while (x != len)
	{
		aux = ft_atoi(argv[x + 1]);
		a[x] = aux;
		printf(" <%i> ", a[x]);
		x++;
	}
	return (a);
}

int *ft_clean(int *a, int len)
{
	int	*c;
	int	x;
	int	aux;
	int	y;
	
	x = 0;
	y = 1;
	c = malloc(sizeof(int) * len);
	while (x != len)
	{
		c[x] = a[x];
		x++;
	}
	while (y != len)
	{
		x = 0;
		y = 0;
		while (x != len)
		{
			if (c[x] > c[x + 1])
			{
				aux = c[x];
				c[x] = c[x + 1];
				c[x + 1] = aux;	
			}
			else 
				y++;
			x++;
		}
	}
	return (c);
}

void	ft_three(t_strc_gen est)
{
	int	min;
	int	max;

	min = ft_get_less(est, est.a);
	max = ft_get_max(est, est.a);

	printf("    - %i-     ", min);
	printf("    - %i-     ", max);

	if (est.a[1] == min)
	{
		if (est.a[2] == max)
			ft_swap_a(est);
		else
			ft_rot_a(est);
	}
	else if (est.a[1] == max)
	{
		if (est.a[0] == min)
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

void ft_five(t_strc_gen est)
{
	int	min;
	int	max;

	min = ft_get_less(est, est.a);
	max = ft_get_max(est, est.a);
	ft_pass_a(est);
	ft_pass_a(est);
	ft_three(est);
	ft_pass_b(est);
	if (est.a[0] == max)
		ft_rrot_a(est);
	else
	{
		if (est.a[0] > est.a[1])
			
	}
	
}

void ft_clean_max(t_strc_gen est)
{
	free(est.a);
	free(est.b);
	free(est.c);
}
int	main(int argc, char **argv)
{
	t_strc_gen	est;
	int			*c;
	int			x;

	x = 0;
	est.longa = argc -1;
	est.a = ft_get_number(est.longa, argv);
	c = ft_clean(est.a, est.longa);
	while (x != est.longa)
	{
		printf(" - %i- ", c[x]);
		x++;
	}
	if (est.longa == 3)
		ft_three(est);
	else if(est.longa <= 5)
		ft_five(est);
	x = 0;
	while (x != est.longa)
	{
		printf(" - %i- ", c[x]);
		x++;
	}
	ft_clean_max(est);
}

/*int	main(void)
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
	while (x < 5)
	{
		printf(" <%i> ", estruc.a[x]);
		printf(" - %i - ", estruc.b[x]);
		x++;
	}
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
}*/
