/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:47:12 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/23 19:16:42 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "stdlib.h"

typedef	struct	s_block
{
	int		x;
	int		y;
}				t_block;

typedef struct	s_tetris
{
	t_block		*blocks;
	int			width;
	int			height;
}				t_tetris;

typedef struct  s_map
{
	int         **map;
	t_tetris    *t_pcs;
	int			nb_pcs;
}               t_map;

char		*ft_loadf(const char *file);
t_map       *parse_map(char *file);

#endif
