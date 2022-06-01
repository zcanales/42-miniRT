/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:56:29 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/26 10:01:14 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	mouse_press_exit(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
	exit(0);
	return (0);
}

//		mlx_destroy_window(mlx->mlx, mlx->win);
static int	key_press_exit(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

void	mlx_event(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1, key_press_exit, &mlx);
	mlx_hook(mlx->win, 17, 1L << 5, mouse_press_exit, &mlx);
}
