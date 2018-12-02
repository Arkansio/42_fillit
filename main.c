/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:46:12 by mgessa            #+#    #+#             */
/*   Updated: 2018/12/02 19:59:48 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_init(char *file)
{
	t_map	*map;

	map = NULL;
	if (!(map = parse_map(file)))
	{
		ft_putstr_fd("error\n", 1);
		return ;
	}
	ft_resolve(map);
	free_map(map);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_init(argv[1]);
	else
		ft_putstr_fd("Usage: <file>\n", 1);
}
