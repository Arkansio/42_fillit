/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:54:31 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/28 23:42:46 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_load_blocks(t_tetris *tet, int tab[4][4])
{
	int		i;
	int		is_relative;
	int		j;
	int		y;
	int		x;

	j = 1;
	i = 0;
	is_relative = 0;
	while (i < 16)
	{
		if (is_relative == 0 && tab[i / 4][i % 4] == 1)
		{
			tet->blocks[0].y = 0;
			tet->blocks[0].x = 0;
			y = i / 4;
			x = i % 4;
			is_relative = 1;
		}
		else if (tab[i / 4][i % 4] == 1)
		{
			tet->blocks[j].y = i / 4 - y;
			tet->blocks[j].x = i % 4 - x;
			j++;
		}
		i++;
	}
	return (1);
}
