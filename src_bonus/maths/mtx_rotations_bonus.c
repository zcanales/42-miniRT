/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:35:59 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/27 15:51:55 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_mtx	x_rotatation_mtx(double grade)
{
	t_mtx	mtx;

	mtx = identity_mtx(4);
	mtx.data[1][1] = cos((grade * M_PI) / 180);
	mtx.data[1][2] = sin((grade * M_PI) / 180) * (-1);
	mtx.data[2][1] = sin((grade * M_PI) / 180);
	mtx.data[2][2] = cos((grade * M_PI) / 180);
	return (mtx);
}

t_mtx	y_rotatation_mtx(double grade)
{
	t_mtx	mtx;

	mtx = identity_mtx(4);
	mtx.data[0][0] = cos((grade * M_PI) / 180);
	mtx.data[0][2] = sin((grade * M_PI) / 180);
	mtx.data[2][0] = sin((grade * M_PI) / 180) * (-1);
	mtx.data[2][2] = cos((grade * M_PI) / 180);
	return (mtx);
}

t_mtx	z_rotatation_mtx(double grade)
{
	t_mtx	mtx;

	mtx = identity_mtx(4);
	mtx.data[0][0] = cos((grade * M_PI) / 180);
	mtx.data[0][1] = sin((grade * M_PI) / 180) * (-1);
	mtx.data[1][0] = sin((grade * M_PI) / 180);
	mtx.data[1][1] = cos((grade * M_PI) / 180);
	return (mtx);
}
