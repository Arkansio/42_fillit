/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf_tside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:48:55 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/27 20:15:10 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_sides(int map[4][4])
{
	int	i;
	int	sides;
	int	y;
	int	x;

	sides = 0;
	i = 0;
	while (i < 16)
	{
		y = i / 4;
		x = i % 4;
		if (map[y][x] == 1)
		{
			if (y > 0 && map[y - 1][x] == 1)
				sides++;
			if (y < 3 && map[y + 1][x] == 1)
				sides++;
			if (x > 0 && map[y][x - 1] == 1)
				sides++;
			if (x < 3 && map[y][x + 1] == 1)
				sides++;
		}
//		if (i % 4 == 0)
//			ft_putchar('\n');
//		ft_putchar('0' + map[y][x]);
		i++;
	}
	if (sides < 6)
		return (-1);
//	printf("\nSides: %d\n", sides);
//	ft_putstr("\n");
	return (1);
}

int				ft_checkf_tside(char *str)
{
	int			map[4][4];
	//	t_block			blocks[4];

	if (ft_load_tetmap(str, map) == -1)
		return (-1);
//	clock_t begin = clock();
	if (check_sides(map) == -1)
		return (-1);
//	clock_t end = clock();
//	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//	printf("load map: %fs\n", time_spent);
	return (1);
}
