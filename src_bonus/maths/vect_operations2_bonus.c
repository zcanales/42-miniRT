/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:37:55 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/03 14:35:01 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/point_vector.h"
#include "math.h"

t_vect	neg_vect(t_vect v1)
{
	t_vect	v;

	v.x = (-1) * v1.x;
	v.y = (-1) * v1.y;
	v.z = (-1) * v1.z;
	return (v);
}

double	magnitude_vect(t_vect v1)
{
	double	mag;

	mag = 0;
	mag += v1.x * v1.x;
	mag += v1.y * v1.y;
	mag += v1.z * v1.z;
	return (sqrt(mag));
}

t_vect	normalization_vect(t_vect v1)
{
	t_vect	v;
	double	mag;

	mag = magnitude_vect(v1);
	v.x = v1.x / mag;
	v.y = v1.y / mag;
	v.z = v1.z / mag;
	return (v);
}
