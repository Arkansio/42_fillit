/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf_tet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:11:54 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/26 22:19:04 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_line(char *str)
{
	int 	i;
	int		block;

	block = 0;
	i = 0;
	while (i < 4)
	{
		if (str[i] == '#')
			block++;
		else if (str[i] != '.')
			return (-1);
		i++;
	}
	if (str[i] != '\n')
		return (-1);
	return (block);
}

static int	check_tetri(char *str)
{
	int		i;
	int		j;
	int		block;
	int		total_b;

	j = 0;
	i = 0;
	total_b = 0;
	while (i < 4)
	{
		if ((block = check_line(&str[j])) == -1)
			return (-1);
		total_b += block;
		j += 5;
		i++;
	}
	if (total_b != 4)
		return (-1);
	if (ft_checkf_tside(str) == -1)
		return (-1);
	return (1);
}

int			ft_checkf_tet(char *str, t_map *map)
{
	int		pcs;
	int		i;
	int		sz;

	sz = ft_strlen(str);
	pcs = 0;
	i = 0;
	while (i < sz)
	{
		if(check_tetri(&str[i]) == -1)
			return (-1);
		pcs++;
		i += 21;
	}
	map->nb_pcs = pcs;
	printf("pcs: %d\n", pcs);
	return (1);
}
