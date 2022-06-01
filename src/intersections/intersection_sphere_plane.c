/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:03:52 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 14:51:04 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>
#include <float.h>

t_inter	intersect_ray_sph(t_ray ray, t_sphere s)
{
	double		discriminant;
	double		a;
	double		b;
	t_inter		inter;

	a = 0;
	b = 0;
	discriminant = discriminat_ray_sp(ray, s.inverse, &a, &b);
	inter.obj_type = 's';
	inter.point[0] = (((b * (-1)) - sqrt(discriminant)) / (2 * a));
	inter.point[1] = (((b * (-1)) + sqrt(discriminant)) / (2 * a));
	inter.min_point = get_minpoint(inter.point[0], inter.point[1]);
	if (discriminant == 0)
		inter.count = 1;
	else if (discriminant < 0)
		inter.count = 0;
	else
		inter.count = 2;
	return (inter);
}

t_inter	intersect_ray_pln(t_ray ray, t_plane p)
{
	t_inter		inter;
	double		angle;
	t_ray		ray_transform;

	inter.obj_type = 'p';
	angle = dot_product_vect(p.n_vec, ray.direction);
	ray_transform = transform_ray(ray, p.inverse);
	if (ray_transform.direction.y > EPSILON)
	{
		inter.count = 1;
		inter.min_point = ray_transform.origin.y
			/ ray_transform.direction.y * -1;
		return (inter);
	}
	inter.count = 0;
	return (inter);
}

double	discriminat_ray_sp(t_ray ray, t_mtx invert, double *a, double *b)
{
	t_vect	sphere_to_ray;
	double	c;
	t_ray	ray_transform;

	ray_transform = transform_ray(ray, invert);
	sphere_to_ray = sub_point_point(ray_transform.origin,
			create_point(0, 0, 0));
	(*a) = dot_product_vect(ray_transform.direction, ray_transform.direction);
	(*b) = 2 * dot_product_vect(ray_transform.direction, sphere_to_ray);
	c = dot_product_vect(sphere_to_ray, sphere_to_ray) - 1;
	return (((*b) * (*b)) - (4 * (*a) * c));
}
