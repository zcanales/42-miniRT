/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:05:01 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 14:36:02 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	convert_color_to_int(t_color c)
{
	int	color;

	color = ((int)(255 * c.r) << 16) + ((int)(255 * c.g) << 8)
		+ ((int)(255 * c.b));
	return (color);
}

t_color	create_color(double red, double green, double blue)
{
	t_color	new;

	new.r = red;
	new.g = green;
	new.b = blue;
	return (new);
}

t_color	scalar_mul_color(t_color color, double scalar)
{
	t_color	new;

	new.r = color.r * scalar;
	new.g = color.g * scalar;
	new.b = color.b * scalar;
	check_max_color(&new);
	return (new);
}

t_color	mul_color_color(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	check_max_color(&new);
	return (new);
}

t_color	add_color_color(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r + c2.r;
	new.g = c1.g + c2.g;
	new.b = c1.b + c2.b;
	check_max_color(&new);
	return (new);
}
