/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:34:32 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/20 07:59:03 by voksenui         ###   ########.fr       */
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
	while (f.piece[++y])
	{
		x = -1;
		while (f.piece[y][+x])
			f.piece[y][x] == '*' ? count++ : 0;
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
	while (f.piece[++i])
	{
		j = -1;
		while(f.piece[i][++j])
		{
			s_y = y + i;
			c_x = x + j;
			if (f.piece[i][j] == '*' && s_y >= 0 && c_x >= 0
				&& s_y < f.cm.y && c_x < f.cm.x && f.maps[s_y][c_x] != f.bt
				&& (f.maps[s_y][c_x] == f.me || f.maps[s_y][c_x] == '.')
				&& (++v_piece))
				if (f.maps[s_y][c_x] == f.me
					|| f.maps[s_y][c_x] == (f.me - 32))
					(*pos)++;
		}
	}
	return(v_piece);
}

static void		add_np(t_filler f, t_np *o)
{
	int		y;
	int		x;
	int		cnt;
	int		pos;

	cnt = c_piece(f);
	y = -f.cp.y;
	while (y < f.cm.y)
	{
		x = -f.cp.x;
		while (x < f.cm.y)
		{
			pos = 0;
			if (cnt == ch_piece(f, y, x, &pos) && pos == 1)
			{
				o->nmap[o->count].y = y;
				o->nmap[o->count++].x = x;
			}
			x++;
		}
		y++;
	}
}
void			alg_filler(t_filler f)
{
	t_np	o;

	o.count = -1;
	o.nmap = ft_memalloc(sizeof(t_map) * (f.cm.x * f.cm.y * 2 + 1));
	add_np(f, &o);
	write_piece(f, o);
	free(o.nmap);
}
