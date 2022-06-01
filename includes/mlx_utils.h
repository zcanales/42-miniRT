/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:24:22 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/27 11:18:20 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "../lib/mlx/mlx.h"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_wall
{
	int		width;	
	int		height;
	double	pixel_size_x;
	double	pixel_size_y;
}t_wall;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;

}t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_wall	wall;
}t_mlx;

void	mlx_utils_init(t_mlx *mlx);
void	mlx_event(t_mlx *mlx);

#endif
