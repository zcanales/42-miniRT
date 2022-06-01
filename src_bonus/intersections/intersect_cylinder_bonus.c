/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:38:30 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 16:59:10 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/intersections.h"
#include	"../../includes/light.h"
#include	<math.h>
#include	<float.h>

double	discriminat_ray_cy(t_ray ray, t_mtx invert, double *a, double *b)
{
	double	c;
	t_ray	ray_transform;

	ray.direction = normalization_vect(ray.direction);
	(void)invert;
	(void)ray;
	ray_transform = transform_ray(ray, invert);
	(*a) = pow(ray_transform.direction.x, 2)
		+ pow(ray_transform.direction.z, 2);
	(*b) = (2 * ray_transform.origin.x * ray_transform.direction.x)
		+ (2 * ray_transform.origin.z * ray_transform.direction.z);
	c = pow(ray_transform.origin.x, 2) + pow(ray_transform.origin.z, 2) - 1;
	return (((*b) * (*b)) - (4 * (*a) * c));
}

static bool	is_inside_tops_cy(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if ((pow(x, 2) + pow(z, 2)) <= 1)
		return (true);
	return (false);
}

static void	intersect_tops_cy(t_inter *inter, t_ray ray, t_cylinder c, int i)
{
	double	t;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	t = (c.min - ray.origin.y) / ray.direction.y;
	if (is_inside_tops_cy(ray, t))
	{
		inter->count++;
		inter->point[i] = t;
		if (i == 0)
			i = 2;
	}
	t = (c.max - ray.origin.y) / ray.direction.y;
	if (is_inside_tops_cy(ray, t) && i != 2)
	{
		inter->count++;
		inter->point[i] = t;
	}
}

static void	check_intersect_caps(t_inter *inter, t_ray ray, t_cylinder c)
{
	double	temp;
	double	y0;
	double	y1;

	if (inter->point[0] > inter->point[1])
	{
		temp = inter->point[0];
		inter->point[0] = inter->point[1];
		inter->point[1] = temp;
	}
	y0 = ray.origin.y + inter->point[0] * ray.direction.y;
	y1 = ray.origin.y + inter->point[1] * ray.direction.y;
	if (y0 <= c.min || y0 >= c.max)
	{
		inter->count -= 1;
		intersect_tops_cy(inter, ray, c, 0);
	}
	if (y1 <= c.min || y1 >= c.max)
	{	
		inter->count -= 1;
		intersect_tops_cy(inter, ray, c, 1);
	}
}

t_inter	intersect_ray_cyl(t_ray ray, t_cylinder c, double a, double b)
{
	double		discriminant;
	t_inter		inter;

	discriminant = discriminat_ray_cy(ray, c.inverse, &a, &b);
	ray = transform_ray(ray, c.inverse);
	inter.obj_type = 'c';
	inter.count = 0;
	if (fabs(a) < EPSILON)
	{
		intersect_tops_cy(&inter, ray, c, 0);
		intersect_tops_cy(&inter, ray, c, 1);
		inter.min_point = get_minpoint(inter.point[0], inter.point[1]);
		return (inter);
	}
	inter.point[0] = (((b * (-1)) - sqrt(discriminant)) / (2 * a));
	inter.point[1] = (((b * (-1)) + sqrt(discriminant)) / (2 * a));
	if (discriminant == 0)
		inter.count = 1;
	if (discriminant < 0)
		inter.count = 0;
	else
		inter.count = 2;
	check_intersect_caps(&inter, ray, c);
	inter.min_point = get_minpoint(inter.point[0], inter.point[1]);
	return (inter);
}
