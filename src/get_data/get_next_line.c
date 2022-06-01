/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:07:46 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/26 09:08:44 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

char	*find_next_line(char *holder)
{
	char	*line;
	size_t	len;

	if (ft_strchr(holder, '\n'))
	{
		len = ft_strlen(ft_strchr(holder, '\n'));
		line = ft_substr(holder, 0, ft_strlen(holder) - len + 1);
	}
	else
		line = ft_strdup(holder);
	return (line);
}

char	*save_holder(char *buf, char *holder)
{
	char	*holder_new;

	if (!holder)
		holder_new = ft_strdup(buf);
	else
	{
		holder_new = ft_strjoin(holder, buf);
		free(holder);
	}
	free(buf);
	return (holder_new);
}

char	*new_holder(char *holder)
{
	int		len;
	char	*new_holder;

	if (!(ft_strchr(holder, '\n')))
	{
		free(holder);
		return (NULL);
	}
	len = ft_strlen(holder) - ft_strlen(ft_strchr(holder, '\n'));
	new_holder = ft_strdup(&holder[len + 1]);
	free(holder);
	return (new_holder);
}

char	*read_file(int fd, char *holder)
{
	char	*buf;
	int		num_bytes;

	num_bytes = 1;
	while (num_bytes > 0 && !ft_strchr(holder, '\n'))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		num_bytes = read(fd, buf, BUFFER_SIZE);
		if (num_bytes == -1 || (!num_bytes && !holder))
		{
			free(buf);
			return (NULL);
		}
		if (num_bytes == 0 && *holder == 0)
		{
			free(holder);
			free(buf);
			return (NULL);
		}
		buf[num_bytes] = '\0';
		holder = save_holder(buf, holder);
	}
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*holder;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = read_file(fd, holder);
	if (!holder)
		return (NULL);
	line = find_next_line(holder);
	holder = new_holder(holder);
	return (line);
}
