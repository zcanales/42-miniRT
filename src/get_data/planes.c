/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:11:29 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 09:11:30 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	add_planes_list(t_plane **head)
{
	t_plane	*temp;
	t_plane	*new;

	new = (t_plane *)malloc(sizeof(t_plane));
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

t_plane	*get_last_plane_list(t_plane **head)
{
	t_plane	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	create_planes(char *s, t_world *all, int fd)
{
	t_plane	*tmp;
	char	**dd;
	char	**s_temp;

	add_planes_list(&all->plns);
	tmp = get_last_plane_list(&all->plns);
	if (check_character(s, ',') != 7 || check_character(s, ' ') < 3)
		wrong_values_handling(&s, all, fd, 3);
	dd = ft_split(s, ',');
	tmp->pos.x = ft_atof(&dd[0][2], 10);
	tmp->pos.y = ft_atof(dd[1], 10);
	tmp->pos.z = ft_atof(dd[2], 10);
	s_temp = ft_split(dd[2], ' ');
	tmp->n_vec.x = ft_atof(s_temp[1], 10);
	free_2d_array(s_temp);
	tmp->n_vec.y = ft_atof(dd[3], 10);
	tmp->n_vec.z = ft_atof(dd[4], 10);
	s_temp = ft_split(dd[4], ' ');
	tmp->rgb.r = ft_atof(s_temp[1], 10) / 255;
	free_2d_array(s_temp);
	tmp->rgb.g = ft_atof(dd[5], 10) / 255;
	tmp->rgb.b = ft_atof(dd[6], 10) / 255;
	if (check_ranges((void *)tmp, 'p'))
		wrong_values_handling(&s, all, fd, 3);
	free_2d_array(dd);
}
