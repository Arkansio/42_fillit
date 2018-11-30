/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:48:36 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/30 23:06:29 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static int         **create_array(int sz)
{
	int     i;
	int		**tab;
	int		j;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * sz)))
		return (NULL);
	while (i < sz)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * sz)))
			return (NULL);
		j = 0;
		while (j < sz)
			tab[i][j++] = 0;
		i++;
	}
	return (tab);
}

void		show_tab(int size, int **tab)
{
		int		i = 0;
 //   printf("nb blocks: %d\n", map->nb_pcs);
 //   printf("%d\n", size);
	while (i < size * size)
	{
		if (tab[i / size][i % size] == 0)
			ft_putchar('.');
		else
			ft_putchar('A' + tab[i / size][i % size] - 1);
		i++;
		if (i % size == 0)
			ft_putchar('\n');
	}
}

int			remove_bl(t_tetris *tet, t_map *map, int cords[2], int el_todel)
{
	int		i;
	t_block block;

	i = 0;
	if (el_todel <= 0)
		return (1);
	while (i < el_todel)
	{
		block = tet->blocks[i];
		map->map[cords[0] + block.y][cords[1] + block.x] = 0;
		++i;
	}
	return (1);
}

int			can_place(t_tetris *tet, t_map *map, int cords[2], int bl_index)
{
	int		i;
	t_block block;

	i = 0;
	while (i < 4)
	{
		block = tet->blocks[i];
		if (cords[0] + block.y < map->sz && cords[1] + block.x >= 0 && cords[1] + block.x < map->sz)
		{
			if (map->map[cords[0] + block.y][cords[1] + block.x] == 0)
				map->map[cords[0] + block.y][cords[1] + block.x] = bl_index;
			else
			{
				remove_bl(tet, map, cords, i);
				return (0);
			}
		}
		else
		{
			remove_bl(tet, map, cords, i);
			return (0);
		}
		++i;
	}
	return (1);
}

int			is_available(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_pcs)
	{
		if (map->t_pcs[i]->used == 0)
			return (1);
		++i;
	}
	return (0);
}

int			ft_solve(t_map *map, int **tab, int sz)
{
	int		i;
	int		x;
	int		cords[2];

	i = 0;
	if (is_available(map) == 0)
		return (1);
	while (i < map->nb_pcs)
	{
		x = 0;
		while (x < sz * sz && map->t_pcs[i]->used == 0)
		{
			cords[0] = x / sz;
			cords[1] = x % sz;
			if (tab[cords[0]][cords[1]] == 0)
			{
				if (can_place(map->t_pcs[i], map, cords, i + 1) == 1)
				{
					map->t_pcs[i]->used = 1;
					if (ft_solve(map, tab, sz) == 1)
						return (1);
					else
					{
						remove_bl(map->t_pcs[i], map, cords, 4);
						map->t_pcs[i]->used = 0;
					}
				}
			}
			++x;
		}
		++i;
	}
	return (0);
}

int         ft_resolve(t_map *map)
{
    int     size;
    int     **tab;
	int		result;

	size = ft_perfect_square(map->nb_pcs * 4);
	result = 0;
	while (result != 1)
	{
		if	(!(tab = create_array(size)))
			return (-1);
		map->sz = size;
		map->map = tab;
		result = ft_solve(map, tab, size);
		if (result == 0)
			++size;
		if (tab)
			free(tab);
	}
	show_tab(size, tab);
    return (1);
}
