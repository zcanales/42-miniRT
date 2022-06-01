/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:43:51 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/10 12:36:24 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
//1. El world point es el punto que intersecta el rayo con el objeto,
	//del mundo real al mundo dek objeto
//2. Calculamos el vector NORMAL en el mundo del obj, restando
	//el punto de la interseccion con el centro de la esfere
//3. Convertimos el vector NORMAL al mundo real.
//4. En el libro poene la dimension w = 0, nosotros no lo tenemos que hacer.
//5. Normalizamos el vector
t_vect	get_normal_sphere(t_sphere s, t_point world_point)
{
	t_point	object_point;
	t_vect	object_normal;
	t_vect	world_normal;

	object_point = mul_point_mtx(&s.inverse, world_point);
	object_normal = sub_point_point(object_point, create_point(0, 0, 0));
	world_normal = mul_vect_mtx(&s.transpose, object_normal);
	return (normalization_vect(world_normal));
}

t_vect	get_normal_pl(t_plane pl)
{	
	t_vect	object_normal;
	t_vect	world_normal;

	object_normal = create_vect(0, 1, 0);
	world_normal = mul_vect_mtx(&pl.transpose, object_normal);
	return (normalization_vect(world_normal));
}

t_vect	get_normal_cy(t_cylinder cy, t_point world_point)
{
	t_point	object_point;
	t_vect	object_normal;
	t_vect	world_normal;
	double	dist;

	object_point = mul_point_mtx(&cy.inverse, world_point);
	dist = pow(object_point.x, 2) + pow(object_point.z, 2);
	if (dist < 1 && object_point.y <= (cy.min + EPSILON))
		object_normal = create_vect(0, -1, 0);
	else if (dist < 1 && object_point.y >= (cy.max - EPSILON))
		object_normal = create_vect(0, 1, 0);
	else
		object_normal = create_vect(object_point.x, 0, object_point.z);
	world_normal = mul_vect_mtx(&cy.transpose, object_normal);
	return (normalization_vect(world_normal));
}

//1. Calculamos el angulo entre el vector in(el de la luz), y la NORMAL
//2. lo multiplicamos por la normal y por 2
//3. Restar todo al vector de la luz
t_vect	get_reflect_vect(t_vect light_vect, t_vect normal_vect)
{
	double	angle;
	t_vect	temp;

	angle = dot_product_vect(light_vect, normal_vect);
	temp = scalar_mul_vect(normal_vect, (angle * 2));
	return (sub_vect_vect(light_vect, temp));
}

t_color	lighting(t_light light, t_color color, t_point world_point,
			t_vect vect[2])
{
	t_color	effective_color;
	t_vect	light_vect;
	double	angle_light_normal;
	t_vect	reflected_vect;

	effective_color = mul_color_color(color, light.intensity);
	light_vect = normalization_vect(sub_point_point(light.position,
				world_point));
	angle_light_normal = dot_product_vect(light_vect, vect[0]);
	if (angle_light_normal < 0)
		light.diffuse = create_color(0, 0, 0);
	else
	{
		light.diffuse = scalar_mul_color(effective_color, angle_light_normal);
		light.diffuse = scalar_mul_color(light.diffuse, 1);
		reflected_vect = get_reflect_vect(neg_vect(light_vect), vect[0]);
	}
	return ((add_color_color(light.ambient, light.diffuse)));
}
