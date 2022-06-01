/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:08:30 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 14:09:34 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_character(char *s, char c)
{
	char	**temp;
	int		nbr_character;

	temp = ft_split(s, c);
	nbr_character = ft_get_2d_size(temp);
	if (c == ',' && s[ft_strlen(s) - 1] == ',')
		return (0);
	free_2d_array(temp);
	return (nbr_character);
}

size_t	ft_get_2d_size(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	check_range_vect(t_vect v)
{
	if (v.x > 1 || v.y > 1 || v.z > 1)
		return (1);
	if (v.x < -1 || v.y < -1 || v.z < -1)
		return (1);
	return (0);
}

int	check_range_color(t_color c)
{
	if (c.r > 1 || c.g > 1 || c.b > 1)
		return (1);
	if (c.r < 0 || c.g < 0 || c.b < 0)
		return (1);
	return (0);
}

int	check_ranges(void *tmp, char obj)
{
	if (obj == 'C' && check_range_vect(((t_camera *)tmp)->n_vec))
		return (1);
	if (obj == 'A' && check_range_color(((t_amb_light *)tmp)->rgb))
		return (1);
	if (obj == 'p' && (check_range_vect(((t_plane *)tmp)->n_vec)
			|| check_range_color(((t_plane *)tmp)->rgb)))
		return (1);
	if (obj == 's' && (check_range_color(((t_sphere *)tmp)->rgb)))
		return (1);
	if (obj == 'c' && (check_range_vect(((t_cylinder *)tmp)->n_vec)
			|| check_range_color(((t_cylinder *)tmp)->rgb)))
		return (1);
	return (0);
}
