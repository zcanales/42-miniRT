/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:34:29 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 14:51:42 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

t_ray	create_ray(t_point p, t_vect v)
{
	t_ray	r;

	r.origin = p;
	r.direction = v;
	return (r);
}

t_point	position_ray(t_ray ray, double move)
{
	t_point	new_point;
	t_vect	temp_vect;

	temp_vect = scalar_mul_vect(ray.direction, move);
	new_point = add_point_vect(ray.origin, temp_vect);
	return (new_point);
}

t_ray	transform_ray(t_ray r, t_mtx transform)
{
	t_ray	r2;
	t_point	p;
	t_vect	v;

	p = mul_point_mtx(&transform, r.origin);
	v = mul_vect_mtx(&transform, r.direction);
	r2 = create_ray(p, v);
	return (r2);
}
