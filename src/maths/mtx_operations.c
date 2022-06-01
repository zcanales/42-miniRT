/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:48:25 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 09:48:26 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/miniRT.h"

t_mtx	mul_mtx(t_mtx *mtx1, t_mtx *mtx2)
{
	t_mtx	new;
	int		i;
	int		j;
	int		k;
	double	result;

	new = create_mtx(4);
	i = -1;
	while ((unsigned int)++i < mtx1->size)
	{
		j = -1;
		while ((unsigned int)++j < mtx1->size)
		{
			k = -1;
			result = 0.0f;
			while ((unsigned int)++k < mtx1->size)
				result += mtx1->data[i][k] * mtx2->data[k][j];
			new.data[i][j] = result;
		}
	}
	return (new);
}

t_vect	mul_vect_mtx(t_mtx *mtx, t_vect v)
{
	unsigned int	i;
	unsigned int	j;
	double			result;
	double			tup[4];
	double			new[4];

	i = 0;
	tup[0] = v.x;
	tup[1] = v.y;
	tup[2] = v.z;
	tup[3] = 0;
	while (i < mtx->size)
	{
		j = 0;
		result = 0.0f;
		while (j < mtx->size)
		{
			result += mtx->data[i][j] * tup [j];
			j++;
		}
		new[i] = result;
		i++;
	}
	return (create_vect(new[0], new[1], new[2]));
}

t_point	mul_point_mtx(t_mtx *mtx, t_point p)
{
	unsigned int	i;
	unsigned int	j;
	double			result;
	double			tup[4];
	double			new[4];

	i = 0;
	tup[0] = p.x;
	tup[1] = p.y;
	tup[2] = p.z;
	tup[3] = 1;
	while (i < mtx->size)
	{
		j = 0;
		result = 0.0f;
		while (j < mtx->size)
		{
			result += mtx->data[i][j] * tup[j];
			j++;
		}
		new[i] = result;
		i++;
	}
	return (create_point(new[0], new[1], new[2]));
}

t_mtx	sub_mtx(t_mtx *mtx, int x, int y)
{
	int				i;
	int				j;
	unsigned int	k;
	unsigned int	l;
	t_mtx			new;

	new = create_mtx(mtx->size - 1);
	i = -1;
	k = 0;
	l = 0;
	while ((unsigned int)++i < mtx->size)
	{
		j = -1;
		while ((unsigned int)++j < mtx->size)
		{
			if (i != x && j != y)
			{
				new.data[k][l] = mtx->data[i][j];
				l++;
				if ((unsigned int)l == new.size && ++k)
					l = 0;
			}
		}
	}
	return (new);
}
