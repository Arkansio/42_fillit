/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:56:15 by mgessa            #+#    #+#             */
/*   Updated: 2018/12/02 23:31:13 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			free_map(t_map *map)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (i < map->nb_pcs && map->t_pcs != NULL)
	{
		if (map->t_pcs[i] != 0)
		{
			free(map->t_pcs[i]);
			map->t_pcs[i] = NULL;
		}
		++i;
	}
	if (i == 0)
	{
		free(map);
		return ;
	}
	if (map->t_pcs)
		free(map->t_pcs);
	free(map);
}
