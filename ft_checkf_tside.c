/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf_tside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:48:55 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/30 23:27:58 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_sides(int map[4][4])
{
	int	i;
	int	sides;
	int	c[2];

	sides = 0;
	i = -1;
	while (++i < 16)
	{
		c[0] = i / 4;
		c[1] = i % 4;
		if (map[c[0]][c[1]] == 1)
		{
			if (c[0] > 0 && map[c[0] - 1][c[1]] == 1)
				sides++;
			if (c[0] < 3 && map[c[0] + 1][c[1]] == 1)
				sides++;
			if (c[1] > 0 && map[c[0]][c[1] - 1] == 1)
				sides++;
			if (c[1] < 3 && map[c[0]][c[1] + 1] == 1)
				sides++;
		}
	}
	if (sides < 6)
		return (-1);
	return (1);
}

int				ft_checkf_tside(char *str)
{
	int			map[4][4];

	if (ft_load_tetmap(str, map) == -1)
		return (-1);
	if (check_sides(map) == -1)
		return (-1);
	return (1);
}
