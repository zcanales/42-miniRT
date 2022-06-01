/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:22:01 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/26 08:22:11 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

//is_shadowed
//1. Calcular la distancia entre el punto y la fuenta de luz
//2. Crear un rayo desde el punto hacia la fuente de luz

bool	is_shadowed(t_world *world, t_point point)
{
	t_vect	distance_point_light;
	double	distance;
	t_vect	direction;
	t_inter	*closest_inter;

	distance_point_light = sub_point_point(world->light.position, point);
	distance = magnitude_vect(distance_point_light);
	direction = normalization_vect(distance_point_light);
	closest_inter = get_hit(intersect_world(create_ray(point, direction),
				&world->sphs, &world->plns, &world->cyls));
	if (closest_inter->count > 0)
	{
		if (closest_inter->min_point < distance && closest_inter->min_point > 0)
			return (true);
	}
	return (false);
}
