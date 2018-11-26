/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:11:54 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/26 22:24:51 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			show_all(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->nb_pcs)
	{
		j = 0;
		while (j < 4)
		{
			printf("map[%d]->blocks[%d].x : %d\n", i, j, map->t_pcs[i]->blocks[j].x);
			printf("map[%d]->blocks[%d].y : %d\n\n", i, j, map->t_pcs[i]->blocks[j].y);
			j++;
		}
		i++;
	}
}

static int			load_tetriminos(t_map *map, char *file)
{
	char	*str;

	if (!(str = ft_loadf(file)))
		return (-1);
	if (ft_checkf_sz(str) == -1)
		return (-1);
	if (ft_checkf_tet(str, map) == -1)
		return (-1);
	if (ft_load_tet(str, map) == -1)
		return (-1);
	free(str);
	show_all(map);
	(void)map;
//	ft_putstr(str);
	return (1);
}

t_map				*parse_map(char *file)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (load_tetriminos(map, file) == -1)
	{
		free(map);
		return (NULL);
	}
	return (map);
}
