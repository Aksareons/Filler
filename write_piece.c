/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:08:15 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/20 08:18:35 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			ft_module(int x)
{
	return(x < 0 ? -x : x);
}

static int		field_length(t_filler f, t_np o, int iter, int	*range)
{
	int			y;
	int			x;
	int			res;
	int			end;

	end = 0;
	y = -1;
	while (++y < f.cm.y)
	{
		x = -1;
		while (++x < f.cm.x)
			if (f.maps[y][x] == f.bt)
			{
				res = (ft_module(y - o.nmap[iter].y) + ft_module(x - o.nmap[iter].x));
				if (res < *range && ++end)
					*range = res;
			}
	}
	return (end);
}
void		write_piece(t_filler f, t_np o)
{
	int			i;
	int			min;
	int			range;

	i = -1;
	min = 0;
	range = f.cm.x + f.cm.y;
	while (++i < o.count)
		if (field_length(f, o, i, &range) > 0)
			min = i;
	ft_printf("%d %d\n", o.nmap[min].y, o.nmap[min].x);
}