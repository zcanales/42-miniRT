/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:39:40 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 17:18:05 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_VECTOR_H
# define POINT_VECTOR_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}t_vect;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}t_point;

/*PRINT TUPLE*/
void	print_point(t_point p);
void	print_vect(t_vect p);

/*CREAR UN PUNTO O VECTOR*/
t_vect	create_vect(double x, double y, double z);
t_point	create_point(double x, double y, double z);

//Sumas y restas
t_vect	add_vect_vect(t_vect v1, t_vect v2);
t_point	add_point_vect(t_point v1, t_vect v2);

t_point	sub_point_vect(t_point p1, t_vect v2);
t_vect	sub_point_point(t_point v1, t_point v2);
t_vect	sub_vect_vect(t_vect v1, t_vect v2);

//Operacion: divisiones y multiplicaciones 
t_vect	scalar_mul_vect(t_vect v1, double scalar);
t_vect	scalar_div_vect(t_vect v1, double scalar);
t_vect	cross_product_vect(t_vect v1, t_vect v2);
double	dot_product_vect(t_vect v1, t_vect v2);

//vector_operation2
t_vect	normalization_vect(t_vect v1);
double	magnitude_vect(t_vect v1);
t_vect	neg_vect(t_vect v1);
t_vect	transform_vect(t_vect v, double **matrix);

#endif
