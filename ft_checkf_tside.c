/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf_tside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:48:55 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/24 02:48:25 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		load_map(char *str, int map[4][4])
{
	int     i;
	int     j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i * 5 + j] == '#')
				map[i][j] = 1;
			else if (str[i * 5 + j] == '.')
				map[i][j] = 0;
			else
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int		check_sides(int map[4][4], t_blocks blocks[4])
{

}

int				ft_checkf_tside(char *str)
{
	int			map[4][4];
	t_blocks	blocks[4];

	if (load_map(str, map) == -1)
		return (-1);
	if (check_sides(map, blocks) == -1)
		return (-1);	
	return (1);
}
