/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:25:15 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/30 23:21:33 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetris		*get_tet(char *str)
{
	t_tetris	*tet;
	int			map[4][4];

	if (!(tet = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(ft_load_tetmap(str, map)))
		return (NULL);
	ft_load_blocks(tet, map);
	return (tet);
}

int					ft_load_tet(char *str, t_map *map)
{
	int		i;

	i = 0;
	if (!(map->t_pcs = (t_tetris**)malloc(sizeof(t_tetris*) * map->nb_pcs)))
		return (-1);
	while (i < map->nb_pcs)
	{
		if (!(map->t_pcs[i] = get_tet(&str[i * 21])))
			return (-1);
		map->t_pcs[i]->used = 0;
		i++;
	}
	return (1);
}
