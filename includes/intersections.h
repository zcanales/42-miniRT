/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:56:10 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 17:01:47 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "point_vector.h"
# include "objects.h"

typedef struct s_intersection
{
	char					obj_type;
	void					*object;
	int						count;
	double					point[2];
	double					min_point;
	struct s_intersection	*next;
}t_inter;

typedef struct s_ray
{
	t_point	origin;
	t_vect	direction;
}t_ray;

t_ray	create_ray(t_point p, t_vect v);
t_point	position_ray(t_ray ray, double move);
t_ray	transform_ray(t_ray r, t_mtx transform);
double	discriminat_ray_sp(t_ray ray, t_mtx invert, double *a, double *b);
double	discriminat_ray_cy(t_ray ray, t_mtx invert, double *a, double *b);
t_inter	intersect_ray_sph(t_ray ray, t_sphere s);
t_inter	intersect_ray_pln(t_ray ray, t_plane p);
t_inter	intersect_ray_cyl(t_ray ray, t_cylinder c, double a, double b);
t_inter	*create_interlst(t_inter temp);
void	add_intersection(t_inter **head, t_inter *new);
double	get_minpoint(double t1, double t2);
t_inter	*get_hit(t_inter *lst);

#endif
