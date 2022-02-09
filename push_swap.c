/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:47:48 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/24 18:05:54 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_strc_gen *est)
{
	int	num;
	int	sign;
	int	cont;

	num = 0;
	sign = 1;
	cont = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	printf("el str: %c\n", str[0]);
	while (str[cont] >= '0' && str[cont] <= '9' && str[cont] != 0)
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	if (str[cont] != 0 || num < -2147483648 || num > 2147483647)
	{
		est->error = 1;
		return (0);
	}
	return (num * sign);
}
 // split-----------------------------------------------
int ft_count_arg(char *argv)
{
	int num;
	int x;

	num = 0;
	x = 0;
	while(argv[x] != '\0')
	{
		if (argv[x] != ' ')
		{
			num++;
			while (argv[x] != ' ' && argv[x] != 0)
				x++;
		}
		else if (argv[x] == ' ')
		{
			while(argv[x] == ' ')
				x++;
		}
	}
	return (num);
}

static int	ft_len(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0' && s[x] != ' ')
		x++;
	return (x);
}

int get_word(char *s, t_strc_gen *est)
{
	int		x;
	int		wlen;
	char	*aux;

	x = 0;
	wlen = ft_len(s);
	printf("la longitud es:  %i", wlen);
	aux = malloc(sizeof(char) * wlen + 1);
	if (!aux)
		return (0);
	while (x != wlen)
	{
		printf(": %c\n", s[x]);
		x++;
	}
	x = 0;
	while (x != wlen)
	{
		aux[x] = s[x];
		printf("la palabra es: %c", aux[x]);
		x++;
	}
	aux[x] = '\0';
	x = ft_atoi(aux, est);
	return (x);
}

int *ft_split(char *s, t_strc_gen est)
{
	int *aux;
	int	x;
	int	countw;

	x = 0;
	if (!s)
		return (NULL);
	countw = ft_count_arg(s);
	printf("\ncountwords split == %i", countw);
	aux = malloc(sizeof(int) * (countw));
	if (!aux)
		return (NULL);
	while (x != countw)
	{
		while (*s == ' ' && *s != '\0')
			s++;
		aux[x] = get_word(s, &est);
		printf("aux == %i\n", aux[x]);
		while (*s != ' ' && *s != '\0')
			s++;
		x++;
	}
	x = 0;
	/*while(aux[x] != 0)
	{
		printf("---%i---", aux[x]);
		x++;
	}*/
	return (aux);
}

// ----------------------------------split
int *ft_get_number(int longa, char **argv, t_strc_gen *est)
{
	/*
		aqui recojo todos los numeros para tenerlos como int y poder trabajar con ellos 
		Lo primero es tratar los numeros(argumentos) uno a uno y pasarlos por el split y por el atoi
		El split es para quitar los argumentos pasados como "", de tal manera que los tomo y los paso a numeros separados
		El atoi no solo me pasa los argumentos a int si no que tambien lo utilizo para comprobar que los nueros sean numeros

	*/
	int	*a;
	int	num;
	int aux;
	int *auxy;
	int	x;
	int	y;
	int	z;
	int	countw;

	aux = 0;
	num = 0;
	x = 0;
	z = 1;
	y = 0;
	a = malloc(sizeof(int) * longa);
	//recorro todos los argumentos
	while (x != longa)
	{
		num = ft_count_arg(argv[x + 1]);
		printf("\n num : %i\n", num);
		if(num < 0)
			est->error = 1;
		else if(num == 1)
		{
			aux = ft_atoi(argv[z], est);
			printf("Me meto en el num == 1\n");
			printf("el num == 1 %i\n", aux);
			a[x] = aux;
			printf("\na =v= %i\n", a[x]);
		}
		else
		{
			printf("Me meto en el num < 0\n");
			countw = ft_count_arg(argv[x + 1]);
			printf("\ncountwords == %i", countw);
			printf("\ncount x == %i\n",x);
			auxy = malloc(sizeof(int) * (countw));
			auxy = ft_split(argv[z], *est);
			printf("\n post split == %i \n", auxy[0]);
			printf("\n post split == %i \n", auxy[1]);
			printf("\n post split == %i \n", auxy[2]);
			y = 0;
			countw = countw + x;
			while(x != countw)
			{
				a[x] = auxy[y];
				printf("\nnumero post split == %i \n", a[x]);
				y++;
				x++;
			}
			x = countw;
		}
		if (est->error != 0)
			return (0);
		printf("\na =c= %i\n", a[x]);
		x++;
		z++;
	}
	return (a);
}

struct s_strc ft_make_c(t_strc_gen est)
{
	int	x;
	int	aux;
	int	y;
	
	x = 0;
	y = 1;
	est.c = malloc(sizeof(int) * est.longa);
	while (x != est.longa)
	{
		est.c[x] = est.a[x];
		x++;
	}
	while (y != est.longa)
	{
		x = 0;
		y = 1;
		while (x + 1 != est.longa)
		{
			if (est.c[x] == est.c[x + 1])
			{
				est.error = 2;
				return (est);
			}
			if (est.c[x] > est.c[x + 1])
			{
				aux = est.c[x];
				est.c[x] = est.c[x + 1];
				est.c[x + 1] = aux;	
			}
			else 
				y++;
			x++;
		}
	}
	return (est);
}

int ft_get_long_args(int argc, char **argv)
{
	int cont;
	int	x;

	x = 1;
	cont = 0;
	while (x != argc)
	{
		if(ft_count_arg(argv[x]) == 1)
			cont++;
		else
			cont = cont + ft_count_arg(argv[x]);
		x++;
	}
	return (cont);
}

int	main(int argc, char **argv)
{
	t_strc_gen	est;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if(argc == 1)
		return (0);
	est.longa = ft_get_long_args(argc, argv);
	printf("\n long a -- %i --\n", est.longa);
	est.longb = 0;
	est.error = 0;
	est.aux = 3;
	est.count_mov = 0;
	est.a = ft_get_number(est.longa, argv, &est);
	while(y != est.longa)
	{
		printf("\nprinteo a -- %i --\n", est.a[y]);
		y++;
	}
	printf("long a == %i", est.longa);
	est.longc = est.longa;
	if (est.error != 0)
	{
		write(1, "Error 1\n", 7);
		return (0);
	}
	est = ft_make_c(est);
	while (x != est.longc)
	{
		if (est.a[x] == est.c[x])
			y++;
		x++;
	}
	if (y == est.longc)
		return (0);
	est.mid = est.c[est.longa/2];
	if (est.error != 0)
	{
		write(1, "Error 2\n", 7);
		return (0);
	}
	if (est.longa <= 3)
		est = ft_three(est);
	else if (est.longa <= 100)
		est = ft_one_hun(est);
	else
		est = ft_five_hun(est);
	x = 0;
	while (x != est.longa)
	{
		printf(" - %i- ", est.a[x]);
		x++;
	}
	//ft_clean_max(est);
	printf(" \nNUMERO DE MOVIMIENTOS- %i- \n", est.count_mov);
	return (0);
}
/*
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
}
*/
