/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:11:54 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/23 19:53:51 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			load_tetriminos(t_map *map, char *file)
{
	char	*str;

	if(!(str = ft_loadf(file)))
		return (-1);
	(void)map;
	ft_putstr(str);
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
