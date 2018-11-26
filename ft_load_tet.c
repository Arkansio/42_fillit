/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:25:15 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/26 22:35:21 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetris		*get_tet(char *str)
{
	int			i;
	int			j;
	t_tetris	*tet;

	if (!(tet = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (str[i] == '#')
		{
			tet->blocks[j].x = i % 4;
			tet->blocks[j].y = i / 4;
			j++; 
		}
		if (i % 4 == 0)
			str++;
		i++;
	}
	return (tet);
}

int					ft_load_tet(char *str, t_map *map)
{
	int     i;

	i = 0;
	if (!(map->t_pcs = (t_tetris**)malloc(sizeof(t_tetris*) * map->nb_pcs)))
		return (-1);
	while (i < map->nb_pcs)
	{
		if(!(map->t_pcs[i] = get_tet(&str[i * 21])))
			return (-1);
		i++;
	}
	return (1);
}