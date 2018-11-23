/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:57:06 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/23 20:43:15 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*str_realloc(char *str, char *buff)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(str, buff)))
		return (NULL);
	if (str)
		free(str);
	return (tmp);
}

static int		check_ex(int ret, char *str)
{
	if (ret < 0)
	{
		free(str);
		return (0);
	}
	return (1);
}

char			*ft_loadf(const char *file)
{
	char	buff[20 + 1];
	int		ret;
	int		fd;
	char	*str;

	fd = open(file, 0x000);
	if (fd < 0)
		return (NULL);
	if (!(str = ft_strnew(1)))
		return (NULL);
	while ((ret = read(fd, buff, 20 + 1)) > 0)
	{
		buff[ret] = '\0';
		if (!(str = str_realloc(str, buff)))
			return (NULL);
		if (ft_strlen(str) > 20 * 24 + 23)
		{
			free(str);
			ft_putstr("Too many lines in this file?? wtf\n");
			return (NULL);
		}
	}
	if (check_ex(ret, str) == 0)
		return (NULL);
	return (str);
}
