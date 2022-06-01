/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:13:24 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 09:13:25 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	add_spheres_list(t_sphere **head)
{
	t_sphere	*temp;
	t_sphere	*new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new)
		status_error(errno, strerror(errno));
	new->next = NULL;
	new->transform = identity_mtx(4);
	new->inverse = identity_mtx(4);
	new->transpose = identity_mtx(4);
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

t_sphere	*get_last_sphere_list(t_sphere **head)
{
	t_sphere	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	create_spheres(char *s, t_world *all, int fd)
{
	t_sphere	*tmp;
	char		**dd;
	char		**s_temp;

	add_spheres_list(&all->sphs);
	tmp = get_last_sphere_list(&all->sphs);
	if (check_character(s, ',') != 5 || check_character(s, ' ') < 4)
		wrong_values_handling(&s, all, fd, 2);
	dd = ft_split(s, ',');
	tmp->pos.x = ft_atof(&dd[0][2], 10);
	tmp->pos.y = ft_atof(dd[1], 10);
	tmp->pos.z = ft_atof(dd[2], 10);
	s_temp = ft_split(dd[2], ' ');
	tmp->diameter = ft_atof(s_temp[1], 10);
	tmp->rgb.r = ft_atof(s_temp[2], 10) / 255;
	free_2d_array(s_temp);
	tmp->rgb.g = ft_atof(dd[3], 10) / 255;
	tmp->rgb.b = ft_atof(dd[4], 10) / 255;
	if (check_ranges((void *)tmp, 's'))
		wrong_values_handling(&s, all, fd, 3);
	free_2d_array(dd);
}
