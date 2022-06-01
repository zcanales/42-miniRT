/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:44:51 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 13:17:17 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"../../includes/miniRT.h"

int	check_format(char *s)
{
	int	i;
	int	j;
	int	point;

	i = -1;
	while (s[++i])
	{
		point = 0;
		j = i;
		if (s[i] == '+' || s[i] == '-' || s[i] == '.')
		{
			if (s[i] == '.' && i > 0 && !ft_isdigit(s[i - 1]))
				return (1);
			while (s[++j] && !ft_isdigit(s[j]))
				return (1);
		}
		else if (s[i] == ',')
		{
			while (s[++j] && !ft_isdigit(s[j]) && !ft_strchr("+- .", s[j]))
				return (1);
			if (s[i + 1] == '\0')
				return (1);
		}
	}
	return (0);
}

int	check_line_syntax(char *s)
{
	int	i;

	if (s[0] == 'A' || s[0] == 'C' || s[0] == 'L')
		i = 0;
	else if (!ft_strncmp("sp ", s, 3) || !ft_strncmp("pl ", s, 3)
		|| !ft_strncmp("cy ", s, 3))
		i = 2;
	else if (s[0] == '\n')
		i = -1;
	else
		return (0);
	if (check_format(s))
		return (1);
	while (s[++i])
		if (ft_isalpha(s[i]))
			return (1);
	i = 0;
	while (s[i] != '\0' && s[++i] && s[i] != '\n')
	{
		if (ft_isdigit(s[i]) || s[i] == ',' || is_float(s, &i, i - 1, 0))
			continue ;
		else if (s[i] == ' ')
			continue ;
	}
	return (0);
}

static void	get_values(char **line, t_world *all, int i[3])
{
	char	*s;

	s = ft_strtrim(*line, " ");
	free(*line);
	while (s[++i[0]] && s[0] != '\n')
	{
		if (check_line_syntax(s))
			wrong_values_handling(&s, all, i[2], 1);
		if (s[i[0]] == 'A' && ++i[1])
			all->a_light = create_amblight(s, all, i[2]);
		if (s[i[0]] == 'C' && ++i[1])
			all->cam = create_camera(s, all, i[2]);
		else if (s[i[0]] == 'L' && ++i[1])
			all->light = create_light(s, all, i[2]);
		else if (s[i[0]] == 'p' && ++i[1])
			create_planes(s, all, i[2]);
		else if (s[i[0]] == 's' && ++i[1])
			create_spheres(s, all, i[2]);
		else if (s[i[0]] == 'c' && ++i[1])
			create_cylinders(s, all, i[2]);
		if (i[1])
			break ;
	}
	free(s);
}

void	ray_tracing(t_world *world, t_mlx *mlx)
{
	int		x;
	int		y;
	double	world_x;
	double	world_y;

	camera_config(world);
	y = -1;
	while (++y < HEIGHT -1)
	{
		x = -1;
		world_y = world->cam.half_h - (y * world->cam.pix_s);
		while (++x < WIDTH - 1)
		{
			world_x = (-1) * world->cam.half_w - (x * world->cam.pix_s);
			mlx->img.addr[y * WIDTH + x] = convert_color_to_int(color_at(world,
						ray_for_pixel(&world->cam, x, y)));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	int		ar_int[3];
	char	*line;
	t_world	all;
	t_mlx	mlx;

	all = (t_world){.sphs = NULL, .plns = NULL, .cyls = NULL};
	ar_int[2] = basic_error_handling(argc, argv);
	while (1)
	{
		ar_int[0] = -1;
		ar_int[1] = 0;
		line = get_next_line(ar_int[2]);
		if (line == NULL)
			break ;
		get_values(&line, &all, ar_int);
	}
	prepare_object_transformations(&all);
	mlx_utils_init(&mlx);
	mlx_event(&mlx);
	ray_tracing(&all, &mlx);
	mlx_loop(mlx.mlx);
	free_structures(&all);
	close(ar_int[2]);
	return (0);
}
