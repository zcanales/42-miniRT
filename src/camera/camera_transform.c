/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:16:10 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/05/26 08:39:58 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/miniRT.h"
#include	"../../includes/matrix.h"
#include	<math.h>

t_mtx	view_transformation(t_point from, t_point to, t_vect up)
{
	t_mtx		orientation;
	t_mtx		translation;
	t_vect		forward;
	t_vect		left;
	t_vect		true_up;

	forward = normalization_vect(sub_point_point(to, from));
	left = cross_product_vect(forward, up);
	true_up = cross_product_vect(left, forward);
	orientation = identity_mtx(4);
	orientation.data[0][0] = left.x;
	orientation.data[0][1] = left.y;
	orientation.data[0][2] = left.z;
	orientation.data[1][0] = true_up.x;
	orientation.data[1][1] = true_up.y;
	orientation.data[1][2] = true_up.z;
	orientation.data[2][0] = forward.x * -1;
	orientation.data[2][1] = forward.y * -1;
	orientation.data[2][2] = forward.z * -1;
	translation = translation_mtx(from.x * -1, from.y * -1, from.z * -1);
	return (mul_mtx(&orientation, &translation));
}

void	set_camera(t_camera *cam)
{
	double		half_view;
	double		aspect_ratio;

	half_view = tan((cam->fov * (M_PI / 180)) / 2);
	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	if (aspect_ratio >= 1)
	{
		cam->half_w = half_view;
		cam->half_h = half_view / aspect_ratio;
	}
	else
	{
		cam->half_w = half_view * aspect_ratio;
		cam->half_h = half_view;
	}
	cam->pix_s = (cam->half_w * 2) / (double)WIDTH;
}

t_ray	ray_for_pixel(t_camera *cam, double px, double py)
{
	t_ray	ray;
	double	xoffset;
	double	yoffset;
	t_point	world_pt;
	t_point	pixel_pt;

	xoffset = (px + 0.5) * cam->pix_s;
	yoffset = (py + 0.5) * cam->pix_s;
	world_pt = create_point(cam->half_w - xoffset, cam->half_h - yoffset, -1);
	pixel_pt = mul_point_mtx(&cam->invert, world_pt);
	ray.origin = mul_point_mtx(&cam->invert, create_point(0, 0, 0));
	ray.direction = normalization_vect(sub_point_point(pixel_pt, ray.origin));
	return (ray);
}
