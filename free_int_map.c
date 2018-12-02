/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:01:17 by mgessa            #+#    #+#             */
/*   Updated: 2018/12/02 22:16:09 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_int_tab(int **tab, int sz)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < sz)
	{
		if (tab[i] != NULL)
			free(tab[i]);
		else
			return ;
		i++;
	}
	free(tab);
}
