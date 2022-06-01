/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_transform.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:12:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 17:18:56 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_TRANSFORM_H
# define MTX_TRANSFORM_H

# define M_PI   3.14159265358979323846264338327950288
# include "matrix.h" 

//mtx_transform.c
t_mtx	translation_mtx(double x, double y, double z);
t_mtx	scaling_mtx(double x, double y, double z);
t_mtx	shearing_mtx(double shear_arr[6]);
t_mtx	set_transform_mtx(t_mtx before, t_mtx m);

//mtx_rotations.c
t_mtx	x_rotatation_mtx(double grade);
t_mtx	y_rotatation_mtx(double grade);
t_mtx	z_rotatation_mtx(double grade);

#endif
