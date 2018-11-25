/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:46:12 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/25 16:32:20 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <time.h>

static void		ft_init(char *file)
{
	t_map	*map;

	map = NULL;
	if(!(map = parse_map(file)))
	{
		ft_putstr_fd("error\n", 1);
		return ;
	}
}

int		main(int argc, char **argv)
{
	clock_t begin = clock();

	if (argc == 2)
		ft_init(argv[1]);
	else
		ft_putstr_fd("Usage: <file>\n", 1);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spend: %fs\n", time_spent);
}
