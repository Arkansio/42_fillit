/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:36:01 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/30 23:39:06 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_show_tab(int size, int **tab)
{
	int		i;

	i = 0;
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
