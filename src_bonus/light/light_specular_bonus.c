/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:56:09 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 14:56:11 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_color	specular_bonus(t_vect reflected_vect, t_vect ray_vect,
		t_color intensity)
{
	double	angle_reflect_camera;
	t_color	specular;

	angle_reflect_camera = dot_product_vect(reflected_vect,
			neg_vect(ray_vect));
	if (angle_reflect_camera <= 0)
		specular = create_color(0, 0, 0);
	else
		specular = scalar_mul_color(intensity,
				(0.9 * pow(angle_reflect_camera, 200)));
	check_max_color(&specular);
	return (specular);
}
