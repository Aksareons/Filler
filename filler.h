/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:59:49 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/23 14:00:12 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/ft_printf.h"

typedef struct s_filler
{
	char		p_1;
	char		p_2;
	int			nmap[2];
	int			save[2];
	int			m_y;
	int			m_x;
	int			t_y;
	int			t_x;
	int			nm_y;
	int			nm_x;
	char		**elm;
	char		**maps;
}				t_filler;
 

int				write_piece(t_filler f, int **nmap, int ct);
void			alg_filler(t_filler f);
# endif