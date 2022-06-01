/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:03:52 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/26 08:38:49 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersections.h"
#include <math.h>
#include <float.h>

void	add_intersection(t_inter **head, t_inter *new)
{
	t_inter	*temp;

	if (!*head)
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

t_inter	*create_interlst(t_inter temp)
{
	t_inter	*new;

	new = (t_inter *)malloc(sizeof(t_inter));
	if (!new)
		return (NULL);
	new->point[0] = temp.point[0];
	new->point[1] = temp.point[1];
	new->min_point = temp.min_point;
	new->count = temp.count;
	new->obj_type = temp.obj_type;
	new->object = temp.object;
	new->next = NULL;
	return (new);
}

t_inter	*get_hit(t_inter *lst)
{
	t_inter	*temp;
	t_inter	*min_lst;
	double	min;

	temp = lst;
	min_lst = lst;
	min = DBL_MAX;
	while (temp)
	{
		if (temp->count > 0 && temp->min_point < min && temp->min_point >= 0)
		{
			min = temp->min_point;
			min_lst = temp;
		}
		temp = temp->next;
	}
	if (min == DBL_MAX)
		min_lst->count = 0;
	return (min_lst);
}

double	get_minpoint(double t1, double t2)
{
	if (t1 < 0 || t2 < 0)
	{
		if (t1 > 0)
			return (t1);
		else if (t2 > 0)
			return (t2);
		else
			return (t1);
	}
	if (t1 > t2)
		return (t2);
	else
		return (t1);
}
