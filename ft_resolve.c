/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:48:36 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/29 01:00:13 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         ft_resolve(t_map *map)
{
    int     size;

    size = ft_perfect_square(123);
    printf("nb blocks: %d\n", map->nb_pcs);
    printf("%d\n", size);
    return (1);
}