/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:03:20 by zcanales          #+#    #+#             */
/*   Updated: 2021/08/27 13:36:53 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s[i + start] && i < len)
	{
		s2[i] = s[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s_join;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s_join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_join)
		return (NULL);
	while (*s1)
		s_join[i++] = *s1++;
	while (*s2)
		s_join[i++] = *s2++;
	s_join[i] = '\0';
	return (s_join);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*ptr_s;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ptr_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr_s)
		return (NULL);
	while (*s)
		ptr_s[i++] = *s++;
	ptr_s[i] = '\0';
	return (ptr_s);
}
