/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:47:12 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/22 21:15:01 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_map
{
	int			**map;
}				t_map;

typedef struct	s_pnt
{
	int			x;
	int			y;
}				t_pnt;

t_map       *parse_map(char *name_file);

#endif
