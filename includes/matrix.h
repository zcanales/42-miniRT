/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:39:26 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/05/25 17:21:16 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "point_vector.h"

typedef struct s_mtx
{
	double			**data;
	unsigned int	size;
}t_mtx;

t_mtx	create_mtx(unsigned int size);
void	print_mtx(t_mtx *mtx);
void	init_mtx(t_mtx	*mtx, double *v, unsigned int row);
t_mtx	identity_mtx(unsigned int size);
void	free_mtx(t_mtx *mtx);
t_mtx	mul_mtx(t_mtx *mtx1, t_mtx *mtx2);
t_point	mul_point_mtx(t_mtx *mtx, t_point p);
t_vect	mul_vect_mtx(t_mtx *mtx, t_vect v);
t_mtx	transpose_mtx(t_mtx *mtx);

double	det_2d_mtx(t_mtx *mtx);
t_mtx	sub_mtx(t_mtx *mtx, int x, int y);
double	minor_3d_mtx(t_mtx *mtx, unsigned int x, unsigned int y);
double	cofactor_3d_mtx(t_mtx *mtx, unsigned int x, unsigned int y);
double	det_mtx(t_mtx *mtx);

t_mtx	create_cofactor_mtx(t_mtx *mtx);
t_mtx	invert_mtx(t_mtx *mtx);
double	cofactor_4d_mtx(t_mtx *mtx, unsigned int x, unsigned int y);

#endif
