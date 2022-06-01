/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:44:51 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/26 08:39:58 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_camera	create_camera(char *s, t_world *all, int fd)
{
	t_camera	new;
	static int	nbr_camera;
	char		**dd;
	char		**s_temp;

	if ((++nbr_camera != 1) || check_character(s, ',') != 5
		|| check_character(s, ' ') < 4)
		wrong_values_handling(&s, all, fd, 5);
	dd = ft_split(s, ',');
	new.pos.x = ft_atof(&dd[0][1], 10);
	new.pos.y = ft_atof(dd[1], 10);
	new.pos.z = ft_atof(dd[2], 10);
	s_temp = ft_split(dd[2], ' ');
	new.n_vec.x = ft_atof(s_temp[1], 10);
	new.n_vec.y = ft_atof(dd[3], 10);
	free_2d_array(s_temp);
	s_temp = ft_split(dd[4], ' ');
	new.n_vec.z = ft_atof(dd[4], 10);
	new.fov = ft_atoi(s_temp[1]);
	free_2d_array(s_temp);
	free_2d_array(dd);
	if (check_ranges((void *)&new, 'C') || new.fov > 180 || new.fov < 0
		|| !magnitude_vect(new.n_vec))
		wrong_values_handling(&s, all, fd, 5);
	return (new);
}

t_amb_light	create_amblight(char *s, t_world *all, int fd)
{
	t_amb_light	new;
	static int	nbr_amblight;
	char		**dd;
	char		**s_temp;

	if ((++nbr_amblight != 1) || check_character(s, ',') != 3
		|| check_character(s, ' ') < 3)
		wrong_values_handling(&s, all, fd, 5);
	dd = ft_split(s, ',');
	new.rate = ft_atof(&dd[0][1], 10);
	s_temp = ft_split(dd[0], ' ');
	new.rate = ft_atof(s_temp[1], 10);
	new.rgb.r = (double)ft_atoi(s_temp[2]) / 255;
	new.rgb.g = (double)ft_atoi(dd[1]) / 255;
	new.rgb.b = (double)ft_atoi(dd[2]) / 255;
	free_2d_array(s_temp);
	free_2d_array(dd);
	if (check_ranges((void *)&new, 'A'))
		wrong_values_handling(&s, all, fd, 5);
	return (new);
}

//El color de la luz es solo para el bonus. Asique habra que quitar esto
t_light	create_light(char *s, t_world *all, int fd)
{
	t_light		new;
	static int	nbr_light;
	char		**dd;
	char		**s_temp;

	if ((++nbr_light != 1) || check_character(s, ',') != 3
		|| check_character(s, ' ') < 3)
		wrong_values_handling(&s, all, fd, 5);
	dd = ft_split(s, ',');
	new.position.x = ft_atof(&dd[0][1], 10);
	new.position.y = ft_atof(dd[1], 10);
	new.position.z = ft_atof(dd[2], 10);
	s_temp = ft_split(dd[2], ' ');
	new.brightness = ft_atof(s_temp[1], 10);
	free_2d_array(s_temp);
	new.intensity.r = 1 * new.brightness;
	new.intensity.g = 1 * new.brightness;
	new.intensity.b = 1 * new.brightness;
	free_2d_array(dd);
	if (check_ranges((void *)&new, 'L') || new.brightness > 1
		|| new.brightness < 0)
		wrong_values_handling(&s, all, fd, 5);
	return (new);
}
