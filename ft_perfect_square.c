/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perfect_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:50:51 by mgessa            #+#    #+#             */
/*   Updated: 2018/11/30 23:30:19 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_perfect_square(int nb)
{
	float	c;

	c = 0.f;
	while (c * c < nb)
		c += 0.25f;
	if ((int)((float)(int)c - c) == 0)
		return (int)(c);
	return (int)(c + 1);
}
