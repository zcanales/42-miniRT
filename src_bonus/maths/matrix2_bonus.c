/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:49:11 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/05/03 14:35:00 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/miniRT.h"

t_mtx	transpose_mtx(t_mtx *mtx)
{
	t_mtx	new;
	int		i;
	int		j;

	new = create_mtx(4);
	i = -1;
	while ((unsigned int)++i < mtx->size)
	{
		j = -1;
		while ((unsigned int)++j < mtx->size)
			new.data[j][i] = mtx->data[i][j];
	}
	return (new);
}

double	det_2d_mtx(t_mtx *mtx)
{
	double	det;

	det = (mtx->data[0][0] * mtx->data[1][1]);
	det -= (mtx->data[0][1] * mtx->data[1][0]);
	return (det);
}

double	minor_3d_mtx(t_mtx *mtx, unsigned int x, unsigned int y)
{
	t_mtx	sub;
	double	result;

	sub = sub_mtx(mtx, x, y);
	result = det_2d_mtx(&sub);
	free_mtx(&sub);
	return (result);
}

double	det_mtx(t_mtx *mtx)
{
	double			det;
	unsigned int	i;
	t_mtx			sub;

	det = 0;
	i = 0;
	while (i < mtx->size)
	{
		if (mtx->size > 3)
		{
			sub = sub_mtx(mtx, 0, i);
			if (i % 2 != 0)
				det += (mtx->data[0][i] * det_mtx(&sub) * -1);
			else
				det += mtx->data[0][i] * det_mtx(&sub);
			free_mtx(&sub);
		}
		else
			det += mtx->data[0][i] * cofactor_3d_mtx(mtx, 0, i);
		i++;
	}
	return (det);
}

t_mtx	invert_mtx(t_mtx *mtx)
{
	t_mtx			new_original;
	t_mtx			new_trans;
	float			original_det;
	unsigned int	i;
	unsigned int	j;

	new_original = create_cofactor_mtx(mtx);
	original_det = det_mtx(mtx);
	if (original_det == 0)
		status_error(1, "Error: Determinant = 0. Cannot do calculations");
	new_trans = transpose_mtx(&new_original);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new_trans.data[i][j] /= original_det;
			j++;
		}
		i++;
	}
	free_mtx(&new_original);
	return (new_trans);
}
