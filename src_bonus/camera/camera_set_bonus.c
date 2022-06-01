/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:32:58 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/05/25 12:57:18 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/miniRT.h"

void	camera_config(t_world *world)
{
	t_point	to;

	set_camera(&world->cam);
	world->cam.n_vec = normalization_vect(world->cam.n_vec);
	to.x = world->cam.pos.x + world->cam.n_vec.x;
	to.y = world->cam.pos.y + world->cam.n_vec.y;
	to.z = world->cam.pos.z + world->cam.n_vec.z;
	if (world->cam.n_vec.x == 0 && fabs(world->cam.n_vec.y) == 1
		&& world->cam.n_vec.z == 0)
		world->cam.transform
			= view_transformation(world->cam.pos, to, create_vect(0, 0, 1));
	else
		world->cam.transform
			= view_transformation(world->cam.pos, to, create_vect(0, 1, 0));
	world->cam.invert
		= invert_mtx(&world->cam.transform);
}
