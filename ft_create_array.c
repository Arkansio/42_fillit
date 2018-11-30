/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:40:50 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/30 23:42:07 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			**ft_create_array(int sz)
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