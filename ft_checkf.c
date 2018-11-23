/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:18:57 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/23 21:52:30 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int      check_size(char *str)
{
	int     i;
	int     sz;

	sz = ft_strlen(str);
	i = 1;
	while (i <= 26)
	{
		if (sz % (i * 20 + (i - 1)) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int		check_size2(char *str)
{
	int		i;
	int		sz;

	i = 1;
	sz = ft_strlen(str);
	while (i <= 26)
	{
		if (sz == 20 * i + (i - 1))
			return (1);
		i++;
	}
	return (0);
}

int		ft_checkf(char *str)
{
	if (!(check_size(str)))
	{
		free(str);
		return (0);
	}
	if (!(check_size2(str)))
	{
		free(str);
		return (0);
	}
	return (1);
}
