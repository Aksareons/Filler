/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:10:42 by voksenui          #+#    #+#             */
/*   Updated: 2019/02/23 13:45:13 by voksenui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			filler_piece(char *tmp, t_filler *f)
{
	char		*line;
	int			i;

	i = 0;
	f->t_x = 0;
	f->t_y = 0;
	while (tmp[i] && !ft_isdigit(tmp[i]))
		i++;
	while (tmp[i] && tmp[i] != ' ')
		f->t_y = f->t_y * 10 + tmp[i++] - '0';
	i++;
	while (tmp[i] && tmp[i] != ':')
		f->t_x = f->t_x * 10 + tmp[i++] - '0';
	if (f->elm != NULL)
	{
		i = 0;
		while (f->elm[i] != NULL)
			free(f->elm[i++]);
		free(f->elm);
	}
	f->elm = (char **)ft_memalloc(sizeof(char *) * (f->t_y + 1));
	i = 0;
	while (i < f->t_y && get_next_line(0, &line) > 0)
		f->elm[i++] = line;
}

static void			filler_map(char *tmp, t_filler *f)
{
	char		*line;
	int			i;

	i = 0;
	if (f->maps == NULL)
	{
		while (tmp[i] && !ft_isdigit(tmp[i]))
			i++;
		while (tmp[i] && tmp[i] != ' ')
			f->m_y = f->m_y * 10 + tmp[i++] - '0';
		i++;
		while (tmp[i] && tmp[i] != ':')
			f->m_x = f->m_x * 10 + tmp[i++] - '0';
		f->maps = (char **)ft_memalloc(sizeof(char *) * (f->m_y + 2));
	}
	else
		while (f->maps[i] != NULL)
			free(f->maps[i++] - 4);
	i = 0;
	if (get_next_line(0, &line) > 0)
		free(line);
	while (i < f->m_y && get_next_line(0, &line) > 0)
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
			filler_map(line, &f);
		else if (ft_strstr(line, "Piece "))
		{
			filler_piece(line, &f);
			alg_filler(f);
		}
		else if (ft_strstr(line, "voksenui.filler"))
		{
			f.p_1 = line[10] == '1' ? 'O' : 'X';
			f.p_2 = f.p_1 == 'X' ? 'O' : 'X';
		}
		free(line);
	}
	return (0);
}