/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:21:06 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/05/17 09:49:13 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_mtx	create_mtx(unsigned int size)
{
	t_mtx		mtx;
	int			i;

	if (size < 2)
		status_error(1, "Invalid size");
	mtx.data = malloc(sizeof(double *) * size);
	if (!mtx.data)
		status_error(errno, strerror(errno));
	i = -1;
	while ((unsigned int)++i < size)
	{
		mtx.data[i] = malloc(sizeof(double) * size);
		if (!mtx.data[i])
			status_error(errno, strerror(errno));
	}
	mtx.size = size;
	return (mtx);
}

t_mtx	identity_mtx(unsigned int size)
{
	t_mtx	mtx;
	int		i;
	int		j;

	if (size < 2)
		status_error(1, "Invalid size");
	mtx = create_mtx(size);
	i = -1;
	while ((unsigned int)++i < size)
	{
		j = -1;
		while ((unsigned int)++j < size)
		{
			if (i == j)
				mtx.data[i][j] = 1.0;
			else
				mtx.data[i][j] = 0.0;
		}
	}
	return (mtx);
}

void	print_mtx(t_mtx *mtx)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	printf("---MATRIX----------\n");
	while (i < mtx->size)
	{
		j = 0;
		while (j < mtx->size)
		{
			printf("[ %.5f ]  ", mtx->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_mtx(t_mtx *mtx, double *v, unsigned int row)
{
	unsigned int	i;

	i = 0;
	while (i < mtx->size)
	{
		mtx->data[row][i] = v[i];
		i++;
	}
	return ;
}

void	free_mtx(t_mtx *mtx)
{
	unsigned int	i;

	if (!mtx->size)
		return ;
	i = 0;
	while (i < mtx->size)
	{
		free(mtx->data[i]);
		mtx->data[i] = NULL;
		i++;
	}
	free(mtx->data);
	mtx->data = NULL;
}
