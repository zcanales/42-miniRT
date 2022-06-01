/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:54:14 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/21 13:54:21 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	c;

	c = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[c] && s2[c])
	{
		if (s1[c] != s2[c])
			return (1);
		c++;
	}
	if (s1[c] == '\0' && s2[c] == '\0')
		return (0);
	return (1);
}
