/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:47:12 by mgessa            #+#    #+#             */
/*   Updated: 2018/12/03 00:08:59 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define OUTERROR 1

typedef	struct	s_block
{
	int		x;
	int		y;
}				t_block;

typedef struct	s_tetris
{
	t_block		blocks[4];
	int			used;
}				t_tetris;

typedef struct	s_map
{
	int			**map;
	t_tetris	**t_pcs;
	int			nb_pcs;
	int			sz;
}				t_map;

void			free_int_tab(int **tab, int sz);
void			free_map(t_map *map);
int				**ft_create_array(int sz);
void			ft_show_tab(int size, int **tab);
int				ft_perfect_square(int nb);
int				ft_resolve(t_map *map);
int				ft_load_blocks(t_tetris *tet, int tab[4][4]);
int				ft_load_tetmap(char *str, int map[4][4]);
int				ft_load_tet(char *str, t_map *map);
int				ft_checkf_tside(char *str);
int				ft_checkf_tet(char *str, t_map *map);
int				ft_checkf_sz(char *str);
char			*ft_loadf(const char *file);
t_map			*parse_map(char *file);

#endif
