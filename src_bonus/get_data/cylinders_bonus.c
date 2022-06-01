/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:50:13 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 13:51:21 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_cylinder	*get_last_cylinder_list(t_cylinder **head)
{
	t_cylinder	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	add_cylinders_list(t_cylinder **head)
{
	t_cylinder	*temp;
	t_cylinder	*new;

	new = (t_cylinder *)malloc(sizeof(t_cylinder));
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

static void	cylinder_aux(char **dd, t_cylinder *tmp, char **s_temp)
{
	tmp->pos.x = ft_atof(&dd[0][2], 10);
	tmp->pos.y = ft_atof(dd[1], 10);
	tmp->pos.z = ft_atof(dd[2], 10);
	tmp->n_vec.x = ft_atof(s_temp[1], 10);
}

void	create_cylinders(char *s, t_world *all, int fd)
{
	t_cylinder	*tmp;
	char		**dd;
	char		**s_temp;

	dd = NULL;
	add_cylinders_list(&all->cyls);
	tmp = get_last_cylinder_list(&all->cyls);
	if (check_character(s, ',') != 7 || check_character(s, ' ') < 6)
		wrong_values_handling(&s, all, fd, 4);
	dd = ft_split(s, ',');
	s_temp = ft_split(dd[2], ' ');
	cylinder_aux(dd, tmp, s_temp);
	free_2d_array(s_temp);
	tmp->n_vec.y = ft_atof(dd[3], 10);
	tmp->n_vec.z = ft_atof(dd[4], 10);
	s_temp = ft_split(dd[4], ' ');
	tmp->diameter = ft_atof(s_temp[1], 10);
	tmp->height = ft_atof(s_temp[2], 10);
	tmp->rgb.r = ft_atof(s_temp[3], 10) / 255;
	free_2d_array(s_temp);
	tmp->rgb.g = ft_atof(dd[5], 10) / 255;
	tmp->rgb.b = ft_atof(dd[6], 10) / 255;
	if (check_ranges((void *)tmp, 'c'))
		wrong_values_handling(&s, all, fd, 3);
	free_2d_array(dd);
}
