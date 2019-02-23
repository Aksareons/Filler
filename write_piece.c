/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:08:15 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/23 13:45:12 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			ft_module(int x)
{
	return(x < 0 ? -x : x);
}

static int		field_length(t_filler f, int **nmap, int iter, int	*range)
{
	int			y;
	int			x;
	int			res;
	int			end;

	res = 0;
	end = 0;
	y = -1;
	while (++y < f.m_y)
	{
		x = -1;
		while (++x < f.m_x)
			if (f.maps[y][x] == f.p_2)
			{
				res = (ft_module(x - nmap[iter][x]) + ft_module(y - nmap[iter][y]));
				if (res < *range && (++end))
					*range = res;
			}
	}
	return (end);
}
int		write_piece(t_filler f, int **nmap, int ct)
{
	int			i;
	int			min;
	int			range;

	i = -1;
	min = 0;
	range = f.m_x + f.m_y;
	while (++i < ct)
		if (field_length(f, nmap, i, &range))
			min = i;
	return (ft_printf("%d %d\n", nmap[min][f.nm_y], nmap[min][f.nm_x]));
}