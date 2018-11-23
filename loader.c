/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:57:06 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/23 19:14:59 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*str_realloc(char *str, char *buff)
{
    char    *tmp;

    if (!str)
	        return (NULL);
    if (!(tmp = ft_strjoin(str, buf)))
	        return (NULL);
    buf[0] = '\0';
    if (str)
		free(str);
    return (tmp);	
}

char		*ft_loadf(const char *file)
{
	char    buf[20 + 1];
	int     ret;
	int		fd;
	char	*str;

	fd = open(file, 0x000);
	if (fd == -1)
		return (NULL);
	if(!(str = ft_strnew(1)))
		return (NULL);
	while ((ret = read(fd, buf, 20 + 1)) > 0)
	{
		str_realloc(str, buf);
		if (ft_strlen(str) > 20 * 24 + 23)
		{
			free(str);
			return (NULL);
		}
	}
	if (ret == -1)
		return (NULL);
	return (str);
}
