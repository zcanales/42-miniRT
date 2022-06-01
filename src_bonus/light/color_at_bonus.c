/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:15:10 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 17:51:23 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/miniRT.h"

static void	inter_aux(t_inter one_inter, t_inter **head, void *temp)
{
	(one_inter.object) = temp;
	add_intersection(head, create_interlst(one_inter));
}

t_inter	*intersect_world(t_ray ray, t_sphere **s, t_plane **p,
							t_cylinder **c)
{
	t_inter	*head;
	void	*temp;

	temp = (void *)(*s);
	head = NULL;
	while (temp != NULL)
	{
		inter_aux((intersect_ray_sph(ray, *((t_sphere *)temp))), &head, temp);
		temp = ((t_sphere *)temp)->next;
	}
	temp = (void *)(*p);
	while (temp != NULL)
	{
		inter_aux(intersect_ray_pln(ray, *((t_plane *)temp)), &head, temp);
		temp = ((t_plane *)temp)->next;
	}
	temp = (void *)(*c);
	while (temp != NULL)
	{
		inter_aux(intersect_ray_cyl(ray, *((t_cylinder *)temp), 0, 0),
			&head, temp);
		temp = ((t_cylinder *)temp)->next;
	}
	return (head);
}

//1. instantiate a data structure for storing some precomputed values
//2.  copy the intersection's properties, for convenience
//3. precompute some useful values
//4. Hacer una funcione que calcule la normal dependiendo del tipo de objeto
t_comps	prepare_computations(t_inter closest_inter, t_ray ray)
{
	t_comps	comps;

	comps.t = closest_inter.min_point;
	comps.object = closest_inter.object;
	comps.obj_type = closest_inter.obj_type;
	comps.point = add_point_vect(ray.origin,
			scalar_mul_vect(ray.direction, comps.t));
	comps.eyev = neg_vect(ray.direction);
	if (comps.obj_type == 's')
		comps.normalv = get_normal_sphere(*(t_sphere *)comps.object,
				comps.point);
	if (comps.obj_type == 'p')
		comps.normalv = get_normal_pl(*(t_plane *)comps.object);
	if (comps.obj_type == 'c')
		comps.normalv = get_normal_cy(*(t_cylinder *)comps.object,
				comps.point);
	if (dot_product_vect(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = neg_vect(comps.normalv);
	}
	else
		comps.inside = false;
	return (comps);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	bool	shadow;
	t_vect	vect[2];

	vect[0] = comps.normalv;
	vect[1] = neg_vect(comps.eyev);
	shadow = is_shadowed(&world, comps.over_point);
	if (shadow == true)
		return (world.light.ambient);
	if (comps.obj_type == 's')
		return (lighting(world.light, ((t_sphere *)comps.object)->rgb,
				comps.point, vect));
	if (comps.obj_type == 'p')
		return (lighting(world.light, ((t_plane *)comps.object)->rgb,
				comps.point, vect));
	if (comps.obj_type == 'c')
		return (lighting(world.light, ((t_cylinder *)comps.object)->rgb,
				comps.point, vect));
	return (create_color(1, 0, 0));
}

t_color	color_at(t_world *world, t_ray ray)
{
	t_inter	*head_lst;
	t_inter	*closest_inter;
	t_comps	comps;
	t_color	final_color;

	final_color = create_color(0, 0, 0);
	head_lst = NULL;
	closest_inter = NULL;
	head_lst = intersect_world(ray, &world->sphs, &world->plns, &world->cyls);
	closest_inter = get_hit(head_lst);
	if (closest_inter->count > 0)
	{
		comps = prepare_computations(*closest_inter, ray);
		comps.over_point = add_point_vect(comps.point,
				scalar_mul_vect(comps.normalv, EPSILON));
		final_color = shade_hit(*world, comps);
	}
	free_inter_lst(head_lst);
	return (final_color);
}
