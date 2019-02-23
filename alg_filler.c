/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:34:32 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/23 13:45:10 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		c_piece(t_filler f)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	y = -1;
	while (f.elm[++y])
	{
		x = -1;
		while (f.elm[y][++x])
			if (f.elm[y][x] == '*')
				count++;
	}
	return (count);
}

static int		ch_piece(t_filler f, int y, int x, int *pos)
{
	int		i;
	int		j;
	int		s_y;
	int		c_x;
	int		v_piece;

	i = -1;
	v_piece = 0;
	while (f.elm[++i])
	{
		j = -1;
		while(f.elm[i][++j])
		{
			s_y = y + i;
			c_x = x + j;
			if (f.elm[i][j] == '*' && s_y >= 0 && c_x >= 0 && s_y < f.m_y\
			&& c_x < f.m_x && f.maps[s_y][c_x] != f.p_2	&& \
			(f.maps[s_y][c_x] == '.' || f.maps[s_y][c_x] == f.p_1) && (++v_piece))
				if (f.maps[s_y][c_x] == f.p_1 || f.maps[s_y][c_x] == (f.p_1 - 32))
					(*pos)++;
		}
	}
	return(v_piece);
}

static void		add_np(t_filler f, int **nmap, int ct)
{
	int		y;
	int		x;
	int		cnt;
	int		pos;

	cnt = c_piece(f);
	y = -f.t_y - 1;
	while (++y < f.m_y)
	{
		x = -f.t_x - 1;
		while ((++x < f.m_x) && (pos = 0))
			if (cnt == ch_piece(f, y, x, &pos) && pos == 1)
				((nmap[ct][f.nm_y] = y) && (nmap[ct++][f.nm_x] = x));
	}
}

void			alg_filler(t_filler f)
{
	int		*nmap;
	int			ct;

	ct = -1;
	nmap = ft_memalloc(sizeof(int) * (f.m_x + f.m_y + 1));
	while (nmap[++ct])
		nmap[ct] = (int *)ft_memalloc(sizeof(int) * (f.m_x + 5) + 1);
	add_np(f, nmap, ct);
	write_piece(f, nmap, ct);
	free(nmap);
}
