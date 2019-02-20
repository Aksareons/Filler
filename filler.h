/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:59:49 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/20 08:10:53 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	int			x;
	int			y;
}				t_map;

typedef struct s_filler
{
	char		me;
	char		bt;
	char		**piece;
	char		**maps;
	t_map		cm;
	t_map		cp;
}				t_filler;

typedef struct s_np
{
	t_map		*nmap;
	int			count;
}				t_np;

void			write_piece(t_filler f, t_np o);
void			alg_filler(t_filler f);
# endif