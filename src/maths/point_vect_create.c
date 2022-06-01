/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vect_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:59:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 09:59:37 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/point_vector.h"

void	print_point(t_point p)
{
	printf("x->[%.2f] ", p.x);
	printf("y->[%.2f] ", p.y);
	printf("z->[%.2f] ", p.z);
	printf("\n");
}

void	print_vect(t_vect v)
{
	printf("x->[%.2f] ", v.x);
	printf("y->[%.2f] ", v.y);
	printf("z->[%.2f] ", v.z);
	printf("\n");
}

t_vect	create_vect(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point	create_point(double x, double y, double z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
