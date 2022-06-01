/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:32:06 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/26 08:39:37 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "matrix.h"
# include "point_vector.h"
# include "stdbool.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}t_color;

typedef struct s_camera
{
	t_point	pos;
	t_vect	n_vec;
	double	fov;
	double	pix_s;
	double	half_w;
	double	half_h;
	t_mtx	transform;
	t_mtx	invert;
}t_camera;

typedef struct s_amb_light
{
	double	rate;
	t_color	rgb;
}t_amb_light;

typedef struct s_light
{
	t_point		position;
	t_color		diffuse;
	t_color		specular;
	t_color		ambient;
	t_color		intensity;
	double		brightness;
	t_color		rgb;
}t_light;

typedef struct s_sphere
{
	t_point			pos;
	double			diameter;
	t_mtx			transform;
	t_mtx			inverse;
	t_mtx			transpose;
	t_color			rgb;
	struct s_sphere	*next;
}t_sphere;

typedef struct s_plane
{
	t_mtx			transform;
	t_mtx			inverse;
	t_mtx			transpose;
	t_point			pos;
	t_vect			n_vec;
	t_color			rgb;
	struct s_plane	*next;
}t_plane;

typedef struct s_cylinder
{
	t_point				pos;
	t_vect				n_vec;
	double				diameter;
	double				height;
	double				min;
	double				max;
	t_color				rgb;
	t_mtx				transform;
	t_mtx				inverse;
	t_mtx				transpose;
	struct s_cylinder	*next;
}t_cylinder;

typedef struct s_world
{
	t_camera	cam;
	t_amb_light	a_light;
	t_light		light;
	t_sphere	*sphs;
	t_plane		*plns;
	t_cylinder	*cyls;
}t_world;

typedef struct s_computations
{
	char	obj_type;
	void	*object;
	double	t;
	t_point	point;
	t_point	over_point;
	t_vect	eyev;
	t_vect	normalv;
	bool	inside;
}t_comps;

t_camera	create_camera(char *s, t_world *all, int fd);
t_light		create_light(char *s, t_world *all, int fd);
t_amb_light	create_amblight(char *s, t_world *all, int fd);
void		create_planes(char *s, t_world *all, int fd);
void		create_spheres(char *s, t_world *all, int fd);
void		create_cylinders(char *s, t_world *all, int fd);

void		prepare_object_transformations(t_world *world);

size_t		ft_get_2d_size(char **s);
int			extract_values(char **val, double **data, char *type, int i);
void		get_cordinate_data(char **s, double **data, char *obj);
int			check_range_vector(t_vect v);
int			check_range_color(t_color c);
int			check_ranges(void *tmp, char obj);
int			check_character(char *s, char c);
int			is_float(char *s, int *i, int j, int nb);

#endif