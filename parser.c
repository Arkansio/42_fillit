/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:11:54 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/28 23:41:53 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			show_all(t_map *map)
{
	int		i;
	int		j;
	int		t;

	i = 0;
	while (i < map->nb_pcs)
	{
		t = 0;
		j = 0;
		while (j < 16)
		{
			t_block bl = map->t_pcs[i]->blocks[t];
			if (bl.y == j / 4 && bl.x == j % 4)
			{
				t++;
				ft_putchar('#');
				break;
			}
			if (j % 4 == 1)
				ft_putchar('.');
			if ((j + 1) % 4 == 0)
				ft_putchar('\n');
			j++;
		}
		j = 0;
		while (j < 4)
		{
			printf("x: %d ", map->t_pcs[i]->blocks[j].x);
			printf("y: %d\n", map->t_pcs[i]->blocks[j].y);
			j++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
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
