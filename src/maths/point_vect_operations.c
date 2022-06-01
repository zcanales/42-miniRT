/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vect_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:52:37 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/05 14:37:12 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/point_vector.h"

t_vect	add_vect_vect(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_point	add_point_vect(t_point p1, t_vect v2)
{
	t_point	p;

	p.x = p1.x + v2.x;
	p.y = p1.y + v2.y;
	p.z = p1.z + v2.z;
	return (p);
}

t_vect	sub_point_point(t_point p1, t_point p2)
{
	t_vect	v;

	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	v.z = p1.z - p2.z;
	return (v);
}

t_vect	sub_vect_vect(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_point	sub_point_vect(t_point p1, t_vect v2)
{
	t_point	p;

	p.x = p1.x - v2.x;
	p.y = p1.y - v2.y;
	p.z = p1.z - v2.z;
	return (p);
}
