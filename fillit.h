/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:47:12 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/28 18:57:01 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <stdio.h>
# include <time.h>

typedef	struct	s_block
{
	int		x;
	int		y;
}				t_block;

typedef struct	s_tetris
{
	t_block		blocks[4];
	int			width;
	int			height;
}				t_tetris;

typedef struct  s_map
{
	int         **map;
	t_tetris    **t_pcs;
	int			nb_pcs;
}               t_map;

int			ft_load_blocks(t_tetris *tet, int tab[4][4]);
int			ft_load_tetmap(char *str, int map[4][4]);
int			ft_load_tet(char *str, t_map *map);
int			ft_checkf_tside(char *str);
int			ft_checkf_tet(char *str, t_map *map);
int			ft_checkf_sz(char *str);
char		*ft_loadf(const char *file);
t_map       *parse_map(char *file);

#endif
