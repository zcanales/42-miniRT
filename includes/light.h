/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:44:32 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 17:51:42 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "miniRT.h"
# include "math.h"
# define BLACK 0x000000
# define EPSILON 0.00001

//COLOR.c -> Funciones con la estrucutra color.
t_color	create_color(double red, double green, double blue);
t_color	scalar_mul_color(t_color color, double scalar);
t_color	mul_color_color(t_color c1, t_color c2);
t_color	add_color_color(t_color c1, t_color c2);
void	check_color_range(t_color c);
int		convert_color_to_int(t_color c);
void	check_max_color(t_color *c);

//LIGHT.c -> Calcular color teniendo en cuanta la luz
t_vect	get_normal_sphere(t_sphere s, t_point world_point);
t_vect	get_normal_pl(t_plane pl);
t_vect	get_normal_cy(t_cylinder cy, t_point world_point);
t_vect	get_reflect_vect(t_vect light_vect, t_vect normal_vect);
t_color	lighting(t_light light, t_color color, t_point world_point,
			t_vect normal_vect[2]);

//COLOR_AT -> Agrupar todas las funciones para calcular el color en un punto
t_inter	*intersect_world(t_ray ray, t_sphere **s, t_plane **p, t_cylinder **c);
t_comps	prepare_computations(t_inter closest_inter, t_ray ray);
t_color	color_at(t_world *world, t_ray ray);
t_color	shade_hit(t_world world, t_comps comps);

//SHADOWS.C 
bool	is_shadowed(t_world *world, t_point point);

//SPECULAR
t_color	specular_bonus(t_vect reflected_vect,
			t_vect ray_vect, t_color intensity);
#endif
