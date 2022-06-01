# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 09:42:42 by zcanales          #+#    #+#              #
#    Updated: 2022/05/27 08:34:25 by cdiaz-fl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

NAME_BONUS = miniRT_bonus

SRCS =	src/errors_and_frees/error_handling.c\
		src/errors_and_frees/free.c\
		src/errors_and_frees/free2.c\
		src/camera/camera_transform.c\
		src/camera/camera_set.c\
		src/get_data/create_objects.c\
		src/get_data/cylinders.c\
		src/get_data/get_data_utils.c\
		src/get_data/get_data_utils2.c\
		src/get_data/get_next_line.c\
		src/get_data/planes.c\
		src/get_data/spheres.c\
		src/get_data/prepare_objects.c\
		src/get_data/normalization.c\
		src/intersections/intersection_sphere_plane.c\
		src/intersections/intersect_cylinder.c\
		src/intersections/intersect_utils.c\
		src/intersections/ray.c\
		src/maths/matrix1.c\
		src/maths/matrix2.c\
		src/maths/mtx_operations.c\
		src/maths/mtx_cofactor.c\
		src/maths/mtx_transform.c\
		src/maths/mtx_rotations.c\
		src/maths/point_vect_operations.c\
		src/maths/point_vect_create.c\
		src/maths/vect_operations1.c\
		src/maths/vect_operations2.c\
		src/mlx/mlx_utils.c\
		src/mlx/mlx_event.c\
		src/light/color_operations.c\
		src/light/color_operations2.c\
		src/light/color_at.c\
		src/light/light.c\
		src/light/shadows.c\
		src/get_data/main_read.c\

SRCS_BONUS = src_bonus/errors_and_frees/error_handling_bonus.c\
		src_bonus/errors_and_frees/free_bonus.c\
		src_bonus/errors_and_frees/free2_bonus.c\
		src_bonus/camera/camera_transform_bonus.c\
		src_bonus/camera/camera_set_bonus.c\
		src_bonus/get_data/create_objects_bonus.c\
		src_bonus/get_data/cylinders_bonus.c\
		src_bonus/get_data/get_data_utils_bonus.c\
		src_bonus/get_data/get_data_utils2_bonus.c\
		src_bonus/get_data/get_next_line_bonus.c\
		src_bonus/get_data/planes_bonus.c\
		src_bonus/get_data/spheres_bonus.c\
		src_bonus/get_data/prepare_objects_bonus.c\
		src_bonus/get_data/normalization_bonus.c\
		src_bonus/intersections/intersection_sphere_plane_bonus.c\
		src_bonus/intersections/intersect_cylinder_bonus.c\
		src_bonus/intersections/intersect_utils_bonus.c\
		src_bonus/intersections/ray_bonus.c\
		src_bonus/maths/matrix1_bonus.c\
		src_bonus/maths/matrix2_bonus.c\
		src_bonus/maths/mtx_operations_bonus.c\
		src_bonus/maths/mtx_cofactor_bonus.c\
		src_bonus/maths/mtx_transform_bonus.c\
		src_bonus/maths/mtx_rotations_bonus.c\
		src_bonus/maths/point_vect_operations_bonus.c\
		src_bonus/maths/point_vect_create_bonus.c\
		src_bonus/maths/vect_operations1_bonus.c\
		src_bonus/maths/vect_operations2_bonus.c\
		src_bonus/mlx/mlx_utils_bonus.c\
		src_bonus/mlx/mlx_event_bonus.c\
		src_bonus/light/color_operations_bonus.c\
		src_bonus/light/color_operations2_bonus.c\
		src_bonus/light/color_at_bonus.c\
		src_bonus/light/light_bonus.c\
		src_bonus/light/light_specular_bonus.c\
		src_bonus/light/shadows_bonus.c\
		src_bonus/get_data/main_read_bonus.c\


OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = includes/

MAKE = make
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

MLX_A = lib/mlx/libmlx.a
LIB_A = lib/libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SEG_FLAGS = -g3 -fsanitize=address
MLX_FLAGS = -L./lib/mlx -framework OpenGL -framework AppKit $(SEG_FLAGS) #-lmlx 

all: $(NAME)

$(NAME): $(OBJS) $(LIB_A) $(MLX_A)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(MLX_FLAGS) $^ -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIB_A) $(MLX_A)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(MLX_FLAGS) $^ -o $(NAME_BONUS)
	@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was created$(RESET)"

%.o: %.c 
	@$(CC) $(CFLAGS) $(SEG_FLAGS) -Imlx -c $< -o $@

$(LIB_A) : lib/Libft/*.c lib/Libft/libft.h
	@$(MAKE) -C lib/libft/ bonus
	 @echo "$(NAME): $(GREEN)Creating $(LIB_A)...$(RESET)"

$(MLX_A) :
	@$(MAKE) -C lib/mlx/
	@echo "$(NAME): $(GREEN)Creating $(MLX_A)...$(RESET)"

clean :
	@make -C lib/libft/ clean
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	make -C lib/libft/ fclean
	make -C lib/mlx/ clean
	@echo "$(NAME): $(RED)$(LIB_A) was deleted$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY : re all fclean clean bonus

