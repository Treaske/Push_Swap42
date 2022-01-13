/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:11:07 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/13 19:52:02 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_strc
{
	int	*a;
	int	*b;
	int	longa;
	int	longb;
}	t_strc_gen;

struct s_strc	ft_swap_a(t_strc_gen estruc);
struct s_strc	ft_swap_b(t_strc_gen estruc);
struct s_strc	ft_swap(t_strc_gen estruc);

struct s_strc	ft_pass_a(t_strc_gen estruc);
struct s_strc	ft_pass_b(t_strc_gen estruc);

struct s_strc	ft_rot_a(t_strc_gen estruc);
struct s_strc	ft_rot_b(t_strc_gen estruc);
struct s_strc	ft_rot(t_strc_gen estruc);

struct s_strc	ft_rrot_a(t_strc_gen estruc);
struct s_strc	ft_rrot_b(t_strc_gen estruc);
struct s_strc	ft_rrot(t_strc_gen estruc);
#endif