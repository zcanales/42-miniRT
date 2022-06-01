/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_cofactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:51:01 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 09:51:02 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/miniRT.h"

double	cofactor_3d_mtx(t_mtx *mtx, unsigned int x, unsigned int y)
{
	t_mtx	sub;
	double	result;

	sub = sub_mtx(mtx, x, y);
	result = det_2d_mtx(&sub);
	free_mtx(&sub);
	if ((x + y) % 2 != 0)
		result *= -1;
	return (result);
}

double	cofactor_trash_mtx(t_mtx *mtx,
unsigned int x, unsigned int y, unsigned int sum)
{
	t_mtx	sub;
	double	result;

	sub = sub_mtx(mtx, x, y);
	result = det_2d_mtx(&sub);
	free_mtx(&sub);
	if ((sum) % 2 != 0)
		result *= -1;
	return (result);
}

t_mtx	create_cofactor_mtx(t_mtx *mtx)
{
	t_mtx	new;
	t_mtx	sub;
	int		x;
	int		y;

	new = create_mtx(mtx->size);
	x = -1;
	while ((unsigned int)++x < new.size)
	{
		y = -1;
		while ((unsigned int)++y < new.size)
		{
			sub = sub_mtx(mtx, x, y);
			new.data[x][y] = cofactor_trash_mtx(&sub,
					0, 0, x + y) * sub.data[0][0];
			new.data[x][y] += cofactor_trash_mtx(&sub,
					0, 1, x + y + 1) * sub.data[0][1];
			new.data[x][y] += cofactor_trash_mtx(&sub,
					0, 2, x + y + 2) * sub.data[0][2];
			free_mtx(&sub);
		}
	}
	return (new);
}
