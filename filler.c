/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:10:42 by voksenui          #+#    #+#             */
/*   Updated: 2019/03/12 17:26:14 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		piece(char *tmp, t_filler *f)
{
	char		*line;
	int			i;

	i = 0;
	f->cp.x = 0;
	f->cp.y = 0;
	while (tmp[i] && !ft_isdigit(tmp[i]))
		i++;
	while (tmp[i] && tmp[i] != ' ')
		f->cp.y = f->cp.y * 10 + tmp[i++] - '0';
	i++;
	while (tmp[i] && tmp[i] != ':')
		f->cp.x = f->cp.x * 10 + tmp[i++] - '0';
	if (f->piece != NULL)
	{
		i = 0;
		while (f->piece[i] != NULL)
			free(f->piece[i++]);
		free(f->piece);
	}
	f->piece = (char **)ft_memalloc(sizeof(char *) * (f->cp.y + 1));
	i = 0;
	while (i < f->cp.y && get_next_line(0, &line) > 0)
		f->piece[i++] = line;
}

static void		maps(char *tmp, t_filler *f)
{
	char		*line;
	int			i;

	i = 0;
	if (f->maps == NULL)
	{
		while (tmp[i] && !ft_isdigit(tmp[i]))
			i++;
		while (tmp[i] && tmp[i] != ' ')
			f->cm.y = f->cm.y * 10 + tmp[i++] - '0';
		i++;
		while (tmp[i] && tmp[i] != ':')
			f->cm.x = f->cm.x * 10 + tmp[i++] - '0';
		f->maps = (char **)ft_memalloc(sizeof(char *) * (f->cm.y + 2));
	}
	else
		while (f->maps[i] != NULL)
			free(f->maps[i++] - 4);
	i = 0;
	if (get_next_line(0, &line) > 0)
		free(line);
	while (i < f->cm.y && get_next_line(0, &line) > 0)
		f->maps[i++] = line + 4;
}

int				main(void)
{
	char		*line;
	t_filler	f;

	ft_bzero(&f, sizeof(f));
	while ((get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "Plateau "))
			maps(line, &f);
		else if (ft_strstr(line, "Piece "))
		{
			piece(line, &f);
			alg_filler(f);
		}
		else if (ft_strstr(line, "voksenui.filler"))
		{
			f.me = line[10] == '1' ? 'O' : 'X';
			f.bt = f.me == 'X' ? 'O' : 'X';
		}
		free(line);
	}
	return (0);
}