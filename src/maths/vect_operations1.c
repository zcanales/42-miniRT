/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:09:48 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/28 13:50:18 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/point_vector.h"

t_vect	scalar_mul_vect(t_vect v1, double scalar)
{
	t_vect	v;

	v.x = v1.x * scalar;
	v.y = v1.y * scalar;
	v.z = v1.z * scalar;
	return (v);
}

t_vect	scalar_div_vect(t_vect v1, double scalar)
{
	t_vect	v;

	if (scalar == 0)
	{
		write(2, "Error: scalar div = 0\n", 23);
		v.x = 0;
		v.y = 0;
		v.z = 0;
		return (v);
	}
	v.x = v1.x / scalar;
	v.y = v1.y / scalar;
	v.z = v1.z / scalar;
	return (v);
}

t_vect	cross_product_vect(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

double	dot_product_vect(t_vect v1, t_vect v2)
{
	double	cross;

	cross = 0;
	cross += v1.x * v2.x;
	cross += v1.y * v2.y;
	cross += v1.z * v2.z;
	return (cross);
}
